// shanting.c ɽͤ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"ɽͤ"NOR);
        set("long",@LONG
������ɽ��Ψһ��һ��Сͤ������ɽ��������Ϣ�ĺõط���������������
С�����ڲ�ͣ��æµ�ţ���Ϊ���Ƕ�Ľ����֮������Ľ�Ž���֮������������
��ٵ����ս��ڣ������и��ɵ�������ʿ����ٹ��ˡ�����һЩ�����ӵ�����
���������ˣ����뵽���������ߣ�ϣ���ܼ����Ž���һ�档��ͨ��������֮·
ȷʵ�����ߣ�����˵���ֻ������ȴ����������������Ϣ��׼����ɽ�����ߵ�
�����Ѳ���������ĺ����ˡ�
LONG);
        set("exits",([
              "northdown" : __DIR__"sshanlu5",
              "westup" : __DIR__"sshanlu6",
        ]));
        set("objects", ([
                __DIR__"npc/xiaofan" :      1 ,
	]));

        set("coor/x",-310);
  set("coor/y",120);
   set("coor/z",60);
   set("coor/x",-310);
 set("coor/y",120);
   set("coor/z",60);
   setup();
        set("outdoors", "���̹�����");
}
