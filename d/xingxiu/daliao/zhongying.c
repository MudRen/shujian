
inherit ROOM;

void create()
{
	set("short", "��Ժ��Ӫ");
	set("long", @LONG
������������Ժ���ʴ�Ӫ����Լ��Բ����ʮ�ɣ���ƽ����������˼���һ
�������ڳ�����Ϊ���ӣ�����һ�Ű������ڶ����;��²�����������еģ�
�������ĺ��ĵش������ر����ء�

LONG
	);

           set("quest",1);
	set("exits", ([
		"west" : __DIR__"zuotang",
		"east" : __DIR__"youtang",
		"north" : __DIR__"liangcang",
		"south" : __DIR__"yingmen",
	]));
  set("outdoor","����");
  setup();
}
#include "daliao.h";
