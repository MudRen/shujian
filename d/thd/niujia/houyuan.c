//Created by Redhat@Sjmud 2009/4/7
//updated by Zhuifeng@SJFY 2010/7/27

inherit ROOM;
#include <ansi.h>
#define QUESTDIR "quest/���Ӣ�۴�/��ѩ����/"

void create()
{
	set("short", GRN "��Ժ" NOR);
	set("long",@long
������Ǵ��������ļҵĺ�Ժ��Ժ������ʺ����ӱ�ɵ�դ����
Ժ������һС������˺ü����߲ˣ��˵��Ա�����Ͽ���һ�ѳ�ͷ��
long);
  set("indoors", "ţ�Ҵ�");
	set("exits",([
		"south" : __DIR__"yangjia",
		"north" : __DIR__"mafang",
]));
            set("quest",1);
            	            set("objects",([
               __DIR__"npc/yang": 1,
               __DIR__"npc/bao": 1,
            ]));
	//set("no_fight", 1);
	setup();
}


