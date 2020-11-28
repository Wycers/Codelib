import json

from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics import roc_auc_score
from sklearn.model_selection import train_test_split

if __name__ == '__main__':

    # Load data
    path = 'train.json'

    with open("train.json") as f:
        txt = f.read()
        data = json.loads(txt)

    reviews = []
    for item in data:
        reviews.append(item['review'])

    # print(reviews)
    # print(len(reviews))
    # print(data[0])

    x_train, x_test, y_train, y_test = train_test_split(
        [x['review'] for x in data],
        [x['sentiment'] for x in data],
        random_state=3,
        test_size=0.05
    )

    tv = TfidfVectorizer(max_features=3000, ngram_range=(1, 2))
    tv.fit(x_train)

    classifier = RandomForestClassifier()
    classifier.fit(tv.transform(x_train), y_train)
    classifier.score(tv.transform(x_test), y_test)

    y_pred = classifier.predict_proba(tv.transform(x_test))[:, 1]
    roc_auc_score(y_test, y_pred)

    # Load test data
    path = 'test.json'

    with open("test.json") as f:
        txt = f.read()
        data = json.loads(txt)

    cnt = 0
    for item in data:
        # print(ite
        res = classifier.predict_proba(tv.transform([item['review']]))[0]
        if res[0] > res[1]:
            res = 0
        else:
            res = 1
        if res == item['sentiment']:
            cnt += 1
    print(cnt, len(data), cnt / len(data))
