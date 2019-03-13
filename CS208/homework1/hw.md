# Assignment1

## Author

11711918 吴烨昌

## Solution

1. False. Here is a counterexample.

   |      |  0   |  1   |
   | :--: | :--: | :--: |
   |  w1  |  m1  |  m2  |
   |  w2  |  m2  |  m1  |

   |      |  0   |  1   |
   | :--: | :--: | :--: |
   |  m1  |  w2  |  w1  |
   |  m2  |  w1  |  w2  |

2. True. If only m is unmatched, when he propose for w, since m is the first of her, w will accept m become (w, m) whenever w was matched or not. At first m must be unmatched, thus (w, m) is ought to form. Once (w, m) is formed, since m is the first of w, w will not accept others. So (w, m) is a stable match. Therefore the pair (m, w) must belong to S.

3. No. Here is a counterexample.
    |      |  0   |  1   |
    | :--: | :--: | :--: |
    |  S1  |  T1  |  T2  |
    |  S2  |  T2  |  T1  |

    |      |  0   |  1   |
    | :--: | :--: | :--: |
    |  T1  |  S2  |  S1  |
    |  T2  |  S1  |  S2  |

    In this situation, if (S1, T1) (S2, T2), B will reproduce schedule to (S1, T2), (S2, T1), then, A will reproduce schedule to (S2, T2), (S1, T1)....

4. If a woman can get a better partner after switching a pair of preferences, that means if the original preference is A > B > C, and she switch to A > C > B:
      1. If she accept B, she will have no choice to get A as her partner.
      2. If she accept C,  B will go to get another woman, leading that A becomes single. Then A go to get she, she successfully get a better partner.

      From rules above, here is an example:

      | M   | 0 | 1 | 2 |
      | :--: | :--: | :--: | :--: |
      | A   | 2 | 1 | 3 |
      | B   | 1 | 2 | 3 |
      | C   | 1 | 2 | 3 |

      |  W   |  0   |  1   |  2   |
      | :--: | :--: | :--: | :--: |
      |  1   |  A   |  B   |  C   |
      |  1'  |  A   |  C   |  B   |
      |  2   |  B   |  A   |  C   |
      |  3   |  C   |  A   |  B   |

      

      In this case

      - if w1 use list 1, there will be (A, 2)(B, 1)(C, 3), w1 will not get A as her partner,

      - if w1 use list 1', there will be (A, 1) (B, 2) (C, 3), w1 will get A as her partner, which is a better partner than list 1.

