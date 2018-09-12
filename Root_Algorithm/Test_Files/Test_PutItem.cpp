//
// Created by DongHoon Kim on 04/09/2018.
//

/*
Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
This file is licensed under the Apache License, Version 2.0 (the "License").
You may not use this file except in compliance with the License. A copy of
the License is located at
http://aws.amazon.com/apache2.0/
This file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
*/
#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/PutItemRequest.h>
#include <aws/dynamodb/model/PutItemResult.h>
#include <iostream>


/**
* Put an item in a DynamoDB table.
*
* Takes the name of the table, a name (primary key value) and a greeting
* (associated with the key value).
*
* This code expects that you have AWS credentials set up per:
* http://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/credentials.html
*/
int main(int argc, char** argv)
{
    const std::string USAGE = \
        "Usage:\n"
        "    put_item <table> <name> [field=value ...]\n\n"
        "Where:\n"
        "    table    - the table to put the item in.\n"
        "    name     - a name to add to the table. If the name already\n"
        "               exists, its entry will be updated.\n\n"
        "Additional fields can be added by appending them to the end of the\n"
        "input.\n\n"
        "Example:\n"
        "    put_item Cellists Pau Language=ca Born=1876\n";

    Aws::SDKOptions options;

    Aws::InitAPI(options);
    {
        Aws::Client::ClientConfiguration clientConfig;
        clientConfig.region = "ap-northeast-2";
        Aws::DynamoDB::DynamoDBClient dynamoClient(clientConfig);

        Aws::DynamoDB::Model::PutItemRequest pir;
        pir.SetTableName("Path_Found_1414");

        Aws::DynamoDB::Model::AttributeValue CR;
        CR.SetS("10199, 20299, 30399");
        pir.AddItem("Certain_Root", CR);

        Aws::DynamoDB::Model::AttributeValue CP;
        CP.SetS("101 202");
        pir.AddItem("Calculated_Path",CP);

        /*
        for (int x = 3; x < argc; x++)
        {
            const Aws::String arg(argv[x]);
            const Aws::Vector<Aws::String>& flds = Aws::Utils::StringUtils::Split(arg, ':');
            if (flds.size() == 2)
            {
                Aws::DynamoDB::Model::AttributeValue val;
                val.SetS(flds[1]);
                pir.AddItem(flds[0], val);
            }
            else
            {
                std::cout << "Invalid argument: " << arg << std::endl << USAGE;
                return 1;
            }
        }
        */

        const Aws::DynamoDB::Model::PutItemOutcome result = dynamoClient.PutItem(pir);
        if (!result.IsSuccess())
        {
            std::cout << result.GetError().GetMessage() << std::endl;
            return 1;
        }
        std::cout << "Done!" << std::endl;
    }
    Aws::ShutdownAPI(options);
    return 0;
}