// /d/wudang/yuzhengong.c ���湬
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"���湬"NOR);
        set("long", @LONG
�����ǽ���ͽ��㻹Ը�����湬�����䵱ɽ�ĵ�һ�������
�ޱȣ����ʢ�����й������������������������˱չ��Ѿã���
�˲�֪���Ƿ������˼䣬��䴫˵���ѵõ����ţ��������Ĥ�ݡ���
����ר�����������Ϣ�Ĳ�ͤ��
LONG
        );
        set("exits", ([
                "westup" : __DIR__"wdbolin",
                "north" :__DIR__"sldadao",
        ]));

        set("objects",([
                "/kungfu/class/wudang/zhike" : 1,
                __DIR__"obj/gdxiang" : 1,
        ]));
        
        set("coor/x",20);
  set("coor/y",-10);
   set("coor/z",30);
   setup();

}
