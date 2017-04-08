/*
 *   based on the tutorials:
 *       https://blog.risingstack.com/writing-native-node-js-modules/
 *       https://nodeaddons.com/
 *   uses https://github.com/nodejs/nan
 */

#include <nan.h>

NAN_METHOD(WhoAmI) {
    auto message = Nan::New<v8::String>("I'm a node/c++ hero!").ToLocalChecked();
    info.GetReturnValue().Set(message);
}

NAN_METHOD(IsPrime) {
    if (!info[0]->IsNumber()) {
        Nan::ThrowError("argument must be a number!");
        return;
    }
    
    int number = (int) info[0]->NumberValue();
    
    if (number < 2) {
        info.GetReturnValue().Set(Nan::False());
        return;
    }
    
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            info.GetReturnValue().Set(Nan::False());
            return;
        }
    }
    
    info.GetReturnValue().Set(Nan::True());
}

NAN_MODULE_INIT(Initialize) {
    NAN_EXPORT(target, WhoAmI);
    NAN_EXPORT(target, IsPrime);
}

NODE_MODULE(addon, Initialize);
