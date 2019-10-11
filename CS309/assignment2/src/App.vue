<template>
  <el-container style="padding: 50px">
    <el-header>
      <h2>SUSTech Parking Record</h2>
    </el-header>
    <el-main>
      <el-button type="primary" @click.native="visible = true">Create parking record</el-button>
      <el-table :data="records" style="width: 100%; height=100%">
        <el-table-column
          fixed
          prop="plateNumber"
          label="License Plate Number"
          width="200"
          align="center"
          :formatter="row => `粤B${row.plateNumber}`"
        ></el-table-column>
        <el-table-column prop="entranceNumber" label="Entrance Number" width="200" align="center"></el-table-column>
        <el-table-column
          prop="arrivalTime"
          label="Arrival Time"
          width="200"
          align="center"
          :formatter="row => row.arrivalTime ? format(row.arrivalTime): '--'"
        ></el-table-column>
        <el-table-column
          prop="departureTime"
          label="Departure Time"
          width="200"
          align="center"
          :formatter="row => row.departureTime ? format(row.departureTime) : '--'"
        ></el-table-column>
        <el-table-column prop="staffName" label="Staff Name" width="120" align="center"></el-table-column>
        <el-table-column prop="staffNumber" label="Staff Number" width="120" align="center"></el-table-column>
        <el-table-column prop="status" label="Status" width="120" align="center"></el-table-column>

        <el-table-column fixed="right" label="Operations" width="120">
          <template slot-scope="scope">
            <el-button
              @click.native.prevent="removeRecord(scope.$index, records)"
              type="danger"
              size="small"
              align="center"
            >Remove</el-button>
          </template>
        </el-table-column>
      </el-table>

      <el-dialog :visible.sync="visible" title="Create parking record">
        <el-form status-icon ref="form" :rules="rules" :model="form" label-width="auto">
          <el-form-item label="License Plate Number" prop="plateNumber">
            <el-input placeholder="Please input..." v-model="form.plateNumber">
              <template slot="prepend">粤B</template>
            </el-input>
          </el-form-item>
          <el-form-item label="Entrance Number" prop="entranceNumber">
            <el-input
              placeholder="Please input..."
              type="number"
              v-model.number="form.entranceNumber"
            ></el-input>
          </el-form-item>
          <el-form-item label="Arrival Time" prop="arrivalTime">
            <el-date-picker
              type="datetime"
              placeholder="Select a time"
              v-model="form.arrivalTime"
              style="width: 100%;"
              format="yyyy-MM-dd HH:mm"
            ></el-date-picker>
          </el-form-item>
          <transition name="bounce">
            <el-form-item v-if="form.status === 'Out'" label="Departure Time" prop="departureTime">
              <el-date-picker
                type="datetime"
                placeholder="Select a time"
                v-model="form.departureTime"
                style="width: 100%;"
                format="yyyy-MM-dd HH:mm"
              ></el-date-picker>
            </el-form-item>
          </transition>
          <el-form-item label="Staff Name" prop="staffName">
            <el-input placeholder="Please input..." v-model="form.staffName"></el-input>
          </el-form-item>
          <el-form-item label="Staff Number" prop="staffNumber">
            <el-input placeholder="Please input..." v-model.number="form.staffNumber"></el-input>
          </el-form-item>
          <el-form-item label="Status">
            <el-radio-group v-model="form.status">
              <el-radio label="In"></el-radio>
              <el-radio label="Out"></el-radio>
            </el-radio-group>
          </el-form-item>
          <el-form-item>
            <el-button type="primary" @click="onSubmit">Create now</el-button>
            <el-button type="danger" @click="onCancel">Cancel</el-button>
          </el-form-item>
        </el-form>
      </el-dialog>
    </el-main>
  </el-container>
</template>
<script>
import moment from "moment";
export default {
  data() {
    const validator = (_, __, callback) => {
      if (!this.form.arrivalTime) return callback();
      if (!this.form.departureTime) return callback();
      if (moment(this.form.departureTime).isAfter(this.form.arrivalTime))
        callback();
      else callback(new Error("Departure time should be after arrival time"));
    };
    return {
      visible: false,
      rules: {
        plateNumber: [
          {
            required: true,
            message: "License plate number is required",
            trigger: "blur"
          },
          {
            min: 5,
            max: 6,
            message: "License plate number should be between 5 and 6",
            trigger: "blur"
          },
          {
            validator: (rule, value, callback) =>
              /^([D,F]?[A-Z0-9]{5})$/.test(value)
                ? callback()
                : callback(new Error("Invalid license plate number")),
            trigger: "blur"
          }
        ],
        entranceNumber: [
          {
            required: true,
            message: "Entrance number is required",
            trigger: "blur"
          },
          {
            type: "number",
            message: "Entrance number is not a number",
            trigger: "blur"
          },
          {
            validator: (rule, value, callback) =>
              1 <= value && value <= 7
                ? callback()
                : callback(
                    new Error("Entrance number should be between 1 and 7")
                  )
          }
        ],
        arrivalTime: [
          {
            required: true,
            message: "Arrival time is required",
            trigger: "change"
          },
          {
            validator: validator,
            trigger: "change"
          }
        ],
        departureTime: [
          {
            validator: validator,
            trigger: "change"
          }
        ],
        staffName: [
          {
            required: true,
            message: "Staff name is required",
            trigger: "blur"
          }
        ],
        staffNumber: [
          {
            required: true,
            message: "Staff number is required",
            trigger: "blur"
          },
          {
            validator: (rule, value, callback) =>
              /^[3,5]/.test(value)
                ? callback()
                : callback(
                    new Error("Invalid staff number: not starting with 3 or 5")
                  ),
            trigger: "blur"
          },
          {
            validator: (rule, value, callback) =>
              /^\d{8}$/.test(value)
                ? callback()
                : callback(
                    new Error("Invalid staff number: not a 8-digit number")
                  ),
            trigger: "blur"
          }
        ]
      },
      form: {
        plateNumber: "",
        entranceNumber: 1,
        arrivalTime: null,
        departureTime: null,
        staffName: "ZHANG Yuqun",
        staffNumber: 30001192,
        status: "In"
      },
      records: [
        {
          plateNumber: "66666",
          entranceNumber: 1,
          arrivalTime: new Date("2019-10-10 10:05"),
          departureTime: null,
          staffName: "ZHANG Yuqun",
          staffNumber: 30001192,
          status: "In"
        },
        {
          plateNumber: "12345",
          entranceNumber: 3,
          arrivalTime: new Date("2019-10-10 08:05"),
          departureTime: new Date("2019-10-10 09:30"),
          staffName: "ZHU Yueming",
          staffNumber: 30001219,
          status: "Out"
        }
      ]
    };
  },
  methods: {
    removeRecord(index, rows) {
      rows.splice(index, 1);
    },
    onSubmit() {
      this.$refs.form.validate(valid => {
        if (valid) {
          if (
            this.records.some(
              item =>
                item.plateNumber === this.form.plateNumber &&
                moment(item.arrivalTime).isSame(this.form.arrivalTime, "minute")
            )
          ) {
            this.$alert("Same record exists", "Error", {
              confirmButtonText: "Known"
            });
            return;
          }
          const record = Object.assign({}, this.form);
          console.log(record);
          this.records.push(record);
          this.visible = false;
          this.$refs.form.resetFields();
        } else {
          console.log("error submit!!");
          return false;
        }
      });
    },
    onCancel() {
      this.visible = false;
      this.$refs.form.resetFields();
    },
    format(date) {
      return moment(date).format("YYYY-MM-DD HH:mm");
    }
  }
};
</script>
<style scoped>
.bounce-enter-active {
  animation: bounce-in 0.3s;
}
.bounce-leave-active {
  animation: bounce-in 0.3s reverse;
}
@keyframes bounce-in {
  0% {
    transform: scale(0);
  }
  50% {
    transform: scale(1.2);
  }
  100% {
    transform: scale(1);
  }
}
</style>
