// Room: /d/huashan/wuqiku.c
// Date: Look 99/03/25

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������������Ҫ����ؼ�����ʹ�����˱���Ľ�����Ϊ�����ԣ�����
�޽�����ɽ�ɵ����ý���ʱ�򣬶��ǵ����������ȡ��������Ҳ��ɢ����һЩ
�����ı���������ɽ����ϰ��ʱȡ�á�
LONG
        );
	set("objects",([
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/changjian" : 1,
		__DIR__"obj/gangdao" : 1,
	]));

        set("exits",([
        	"north" : __DIR__"lianwu2",
        	"south" : __DIR__"shuyuan",
	]));
        set("indoors", "��ɽ" );

	set("coor/x",100);
  set("coor/y",-20);
   set("coor/z",80);
   setup();
}
