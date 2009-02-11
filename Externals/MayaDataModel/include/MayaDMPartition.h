/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTITION_H__
#define __MayaDM_PARTITION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMEntity.h"
namespace MayaDM
{
class Partition : public Entity
{
public:
public:
	Partition():Entity(){}
	Partition(FILE* file,const std::string& name,const std::string& parent=""):Entity(file, name, parent, "partition"){}
	virtual ~Partition(){}
	void setAnnotation(const string& an)
	{
		if(an == "NULL") return;
		fprintf(mFile,"\tsetAttr \".an\" -type \"string\" ");
		an.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPartitionType(unsigned int pt)
	{
		if(pt == 0) return;
		fprintf(mFile,"\tsetAttr \".pt\" %i;\n", pt);

	}
	void getSets(size_t st_i)
	{
		fprintf(mFile,"\"%s.st[%i]\"",mName.c_str(),st_i);

	}
	void getEnvironment()
	{
		fprintf(mFile,"\"%s.envr\"",mName.c_str());

	}
protected:
	Partition(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Entity(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTITION_H__