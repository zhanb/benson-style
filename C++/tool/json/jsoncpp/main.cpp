#include <iostream>
#include <string>
#include "json/json.h"

using namespace std;

int genjson(Json::Value &root);
int readjson(string &upload_id,int &code);

int main()
{
	Json::Value root;
	genjson(root);

	Json::FastWriter fast_writer;
	string data_str = fast_writer.write(root);

	cout<<data_str<<endl;
	
	string upload_id;
	int code;
	readjson(upload_id,code);
	cout<<"upload_id:"<<upload_id<<"\ncode:"<<code<<endl;
    return 0;
}

int genjson(Json::Value &root)
{
	root["status"] = 1;
    root["msg"] = "";

    Json::Value data;
    data["email"] = "zhihaibang1";
    data["erp"] = "zhihaibang";

    Json::Value model_peer;
    model_peer["modelId"] = 23;
    model_peer["modeName"] = "测试mod";

    Json::Value bus_array;
    Json::Value bus_peer1;
    bus_peer1["busId"] = "112";
    bus_peer1["busName"] = "我的家园";
    bus_array.append(bus_peer1);

    Json::Value bus_peer2;
    bus_peer2["busId"] = "213";
    bus_peer2["busName"] = "你的家园";
    bus_array.append(bus_peer2);

    model_peer["businesses"] = bus_array;

    Json::Value model_array;
    model_array.append(model_peer);

    data["models"] = model_array;
    root["data"] = data;

    return 0;
}

int readjson(string &upload_id,int &code)
{
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  

    Json::Reader reader;  
    Json::Value root;  
    if (reader.parse(str, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
    {  
        upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000"  
        code = root["code"].asInt();    // 访问节点，code = 100 
    }  
	return 0;
}
