// /d/wudang/sldadao.c ���ִ��
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"���ִ��"NOR);
        set("long", @LONG
������ɽ�������У���Ƭ���ֻ�ɽ���ɣ�εε�дУ����ǹ���
����ȹ�ۣ����䵱ɽװ��ø�����ȶ���! ������ï�ܵ������֣�ż
���б����ŵ�ɽ�������ԱߵĲݴ���ɳ������Ҫȥץ����ȴ�ַ���
�˲ݴԡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"yuzhengong",
                "east" :__DIR__"songlin1",
                "west" :__DIR__"songlin2",
                "northdown" :__DIR__"shijie2",
        ]));

        set("objects",([
                __DIR__"npc/shanji" : 1,

        ]));
        
        set("coor/x",20);
  set("coor/y",0);
   set("coor/z",30);
   setup();

}
