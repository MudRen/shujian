#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	  set("short", "�㳡��");
	  set("long",@long
������һ��ƽƽ�����Ĵ�㳡���㳡���������ɵĵ�����ϰ�䣬������Ȼ
�ǹ㳡�������ȥ���������ˣ���������ɽ��·��
long);
	  set("exits",([
             "northeast" : __DIR__"shanlu04",
             "east" : __DIR__"guangchang",
          ]));
          set("objects",([
	       __DIR__"npc/kl-dizi3" :  1,
          ]));

          set("outdoors", "����");
          setup();
}
