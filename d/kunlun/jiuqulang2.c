// jiuqulang2.c (kunlun)

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
             "southwest" : __DIR__"shanlin1",
             "northeast" : __DIR__"sanshengtang",
          ]));
          set("outdoors", "����");
          setup();
}
