#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����Ȫ");
        set("long",@long
һ����Ȫ˳��ɽ´���£�������㼯��һ̶Ȫˮ������������һ������
������Ȫ���������Ȫˮ����������һʯ���У���������һ��Ȫ���򡰲�
��Ȫ������Ȫ�󺵲��ߣ����ƴ���ʥ½����Ϊ�����е�һȪ����ʫ�˰׾���
����ʫ��ӽ����ƽɽ�ϰ���Ȫ���Ʊ�����ˮ���У��αر���ɽ��ȥ������
�����˼䡱��Ȫ�����в��ң�Ʒ����Ȫ�����ﲻ����
long);
set("outdoors", "suzhou");
set("exits",([
"westdown" : __DIR__"tianpingshan",
]));
set("coor/x",120);
  set("coor/y",-280);
   set("coor/z",10);
   setup();
}
