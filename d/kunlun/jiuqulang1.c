// jiuqulang1.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	  set("short", HIG"������"NOR);
	  set("long",@long
������ǰ���оŽ����������۵�������ˮ�档һ·������������ʯ��Ȫ��
�仨������ˮɫ���ܡ����ߴ����������ӣ�������������ʯΪ������¥��գ�
ת�۴�����Сͤ��ӡ�
long);
	  set("exits",([
             "southwest" : __DIR__"tieqinju",
             "east" : __DIR__"shiqiao",
          ]));
          set("outdoors", "����");
          setup();
}
