/*
 *   based on the tutorials:
 *       https://blog.risingstack.com/writing-native-node-js-modules/
 *       https://nodeaddons.com/
 *   uses https://github.com/nodejs/nan
 */

#include <nan.h>

const int maxValue = 10;
int numberOfCalls = 0;

NAN_METHOD(WhoAmI) {
    auto message = Nan::New<v8::String>("I'm a node/c++ hero!").ToLocalChecked();
    info.GetReturnValue().Set(message);
}

NAN_METHOD(Increment) {
    if (!info[0]->IsNumber()) {
        Nan::ThrowError("argument must be a number!");
        return;
    }
    
    double infoValue = info[0]->NumberValue();
    if (numberOfCalls + infoValue > maxValue) {
        Nan::ThrowError("Counter went thru the roof!");
        return;
    }
    
    numberOfCalls += infoValue;
    
    auto currentNumberOfCalls = Nan::New<v8::Number>(numberOfCalls);
    info.GetReturnValue().Set(currentNumberOfCalls);
}

NAN_MODULE_INIT(Initialize) {
    NAN_EXPORT(target, WhoAmI);
    NAN_EXPORT(target, Increment);
}

NODE_MODULE(addon, Initialize);
