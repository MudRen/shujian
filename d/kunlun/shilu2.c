#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	 set("short", "ʯ·");
	 set("long",@long
����һ���̵�ʮ��ƽ����ʯ��·��·���ɨ�ĸɸɾ����������ȥ������
��Ժ�Ĵ��ţ������ǳ�����������������ɵ���ЪϢ�ĵط��ˡ�
long);
	 set("exits",([
             "north" : __DIR__"xiuxishi",
             "west" : __DIR__"gate",
             "east" : __DIR__"chufang",
         ]));

         set("outdoors", "����");
         setup();
}
