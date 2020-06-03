import program from "commander";
import SocketIO from "socket.io-client";
const io = SocketIO("http://localhost:3000");

program.version("0.0.1").usage("[options] [value ...]");
// .option('-m, --message <string>', 'a string argument')
// .option('-i, --integer <n>', 'input a integet argument.', parseInt)
// .option('-f, --float <f>', 'input a float arg', parseFloat)
// .option('-l, --list <items>', 'a list', list)
// .option('-r, --range <a>..<b>', 'a range', range)

program
  .command("register <number> <deviceId>")
  .description("register a device with deviceId and number")
  .action((number, deviceId) => {
    io.emit("register", {
      number,
      deviceId,
    });
    console.log(`register device ${number} with ${deviceId}`);
  });

program
  .command("report <deviceId> <longitude> <latitude>")
  .description("report device's position")
  .action((deviceId, longitude, latitude) => {
    io.emit("report", {
      deviceId,
      longitude,
      latitude,
    });
    console.log(`${deviceId} is now at (${longitude}, ${latitude})`);
  });

program
  .command("help")
  .description("output help")
  .action(() => {
    console.log(program.helpInformation());
    process.exit(0);
  });

program.parse(process.argv);
