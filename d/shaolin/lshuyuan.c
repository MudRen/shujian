//lshuyuan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"����Ժ"NOR);
	set("long", @LONG
����һ��ƫƧ��СԺ��Ժ����������ߴ�Ļ������Եü����������
������������ɮ����ȡ�����ͷ���֮�أ��㼯�����¸��ɹ��õĸ�����С�
�����似���³�����Ϊ��ֹ�������ˣ�����Ҳһ������������ߡ�Ժ�ſ�վ
������ɮ�����ֳֽ䵶�����ܵ��ػ������  
LONG
	);

	set("exits", ([
		"east" : __DIR__ "huaishu5",
                "north" : __DIR__ "wuqiku",
                "south" : __DIR__ "fangjuku",
        ]));

        set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));

	set("coor/x",20);
  set("coor/y",320);
   set("coor/z",120);
   setup();
}



