// /d/city/xiaopangu.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIW"С�̹�"NOR);
        set("long",@long
С�̹�������һ��������СͥԺ��԰���Ժ�ʯ��ɽΪ����ɽ������������
�����У�����һ�����ȣ���ͷ������ɽ�ȡ�ɽ���£�ˮ���ϣ���ռ�һʯ����
ͨ��ˮ����ͤ��
long);
        set("exits",([
                "west" : __DIR__"nandajie1",
        ]));
        set("objects", ([
                 __DIR__"npc/juyou" : 1,
                        ]));
        set("coor/x",110);
  set("coor/y",-40);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",-40);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",-40);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",-40);
   set("coor/z",0);
   set("incity",1);
	setup();
}
