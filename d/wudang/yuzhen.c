// /d/wudang/yuzhengong.c ���湬
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"���湬"NOR);
        set("long", @LONG
�����ǽ���ͽ��㻹Ը�����湬�����䵱ɽ�ĵ�һ��������ޱȣ���
��ʢ�����й������������������������˱չ��Ѿã����˲�֪���Ƿ�����
�˼䣬��䴫˵���ѵõ����ţ��������Ĥ�ݡ�
LONG
        );
        set("exits", ([
                "westup" : __DIR__"wdbolin",
                "northdown" : __DIR__"gsdao2",
        ]));

        set("outdoors","�䵱");

        set("objects",([
                CLASS_D("wudang")+"/zhike" : 1,
                __DIR__"obj/gdxiang" : 1,
        ]));
        setup();

}
