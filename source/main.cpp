#include <string>
#include <iostream>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4267)
#pragma warning(disable : 4800)
#endif
#include <google/protobuf/util/json_util.h>
#include "test.pb.h"
#ifdef _MSC_VER
#pragma warning(pop)
#endif

int main()
{
	Test example;
	example.set_x(1);
	example.set_y(2);

	google::protobuf::util::JsonPrintOptions options;
	options.add_whitespace = true;
	options.always_print_primitive_fields = false;
	std::string buf;
	if (google::protobuf::util::MessageToJsonString(example, &buf, options) == google::protobuf::util::Status::OK)
	{
		std::cout << "proto3->json:\n" << buf << std::endl;
	}

	Test back;
	if (google::protobuf::util::JsonStringToMessage(buf, &back) == google::protobuf::util::Status::OK)
	{
		std::cout << "json->proto3:\n" <<
			"x = " << back.x() << "\ny = " << back.y() << std::endl;
	}




	return 0;
}