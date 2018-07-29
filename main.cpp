#include <nan.h>
#include<math.h>


NAN_METHOD(Hello) {
    auto message = Nan::New("Hello from C++!").ToLocalChecked();
    info.GetReturnValue().Set(message);
}

NAN_METHOD(IsPrime) {
    if (!info[0]->IsNumber()) {
        Nan::ThrowTypeError("argument must be a number!");
        return;
    }
    
    int number = (int) info[0]->NumberValue();
    
    if (number < 2) {
        info.GetReturnValue().Set(Nan::False());
        return;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            info.GetReturnValue().Set(Nan::False());
            return;
        }
    }
    
    info.GetReturnValue().Set(Nan::True());
}

NAN_MODULE_INIT(Initialize) {
    NAN_EXPORT(target, Hello);
    NAN_EXPORT(target, IsPrime);
}

NODE_MODULE(addon, Initialize);
