#include <nan.h>

#ifdef _WIN32
  #include <Windows.h>
#elif __APPLE__
  #include <CoreFoundation/CoreFoundation.h>
#endif

NAN_METHOD(get) 
{
#ifdef _WIN32
    WCHAR buf[LOCALE_NAME_MAX_LENGTH];
    memset(buf, 0, LOCALE_NAME_MAX_LENGTH);
    GetLocaleInfoEx(LOCALE_NAME_USER_DEFAULT, LOCALE_SNAME, buf, LOCALE_NAME_MAX_LENGTH);
    char buffer[LOCALE_NAME_MAX_LENGTH];
    memset(buffer, 0, LOCALE_NAME_MAX_LENGTH);
    wcstombs(buffer, buf, LOCALE_NAME_MAX_LENGTH);
    v8::Local<v8::String> locale = Nan::New<v8::String>(buffer).ToLocalChecked();
    info.GetReturnValue().Set(locale);
#elif __APPLE__
    CFLocaleRef loc = CFLocaleCopyCurrent();
    CFStringRef string = (CFStringRef)CFLocaleGetValue(loc, kCFLocaleIdentifier);
    CFRelease(loc);
  
    CFIndex length = CFStringGetLength(string);
    const char* buffer = CFStringGetCStringPtr(string, kCFStringEncodingUTF8);
    if (buffer == NULL)
    {
      char* encodedBuffer = (char*)malloc(length * 3);
      CFStringGetCString(string, encodedBuffer, length * 3, kCFStringEncodingUTF8);
      v8::Local<v8::String> locale = Nan::New<v8::String>(encodedBuffer).ToLocalChecked();
      info.GetReturnValue().Set(locale);
      free(encodedBuffer);
    }
    else
    {
      v8::Local<v8::String> locale = Nan::New<v8::String>(buffer).ToLocalChecked();
      info.GetReturnValue().Set(locale);
    }
    CFRelease(string);
#endif
}

NAN_MODULE_INIT(Init) 
{
  NAN_EXPORT(target, get);
}

NODE_MODULE(method, Init);
