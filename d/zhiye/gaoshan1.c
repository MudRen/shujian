// ɽ��1
// gaoshan1.c
// augx@sj 2/27/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long",
"��������ɽ��һ��ɽ�£�ɽ���ϳ��Ų����滨��ݣ����кܶ�����Ķ���
��û��������������ҩ�Ĳ��أ����в�ҩ�����˲�ҩ��
"); 
        
	set("exits",([
		"southdown" : __DIR__"gaoshan0",
	]));
	
	set("yaocai",5);
	set("outdoors", "�ɶ�����");
	set("incity",1);
	setup();
}

#include "gaoshan.h"
