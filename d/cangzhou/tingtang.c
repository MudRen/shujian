// tingtang.c ����
// 2001.9.27 update by Lklv

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������԰��һ��쵹�������ã�˵�����ã�������˵�ǲ����ӡ��ſڵ�
���������Ѿ�����бб����һЩϸľ׮֧���š�ǽ�ϵ���������Ѭ���ǵĺں�
���ۼ���ǽ�Ƕ��ż����ʯͷ���Ա��п�ˮ�ס�һ����ϯ�������˵ص��У���
����ż�������ͷ��
LONG);
        set("resource/water", 1);
	set("drink_msg","$Nſ��ˮ�ױߺ���һ����ˮ��\n");
        set("sleep_room",1);
        set("no_fight", 1);

        set("exits", ([
                "out" : __DIR__"feiyuan",
        ]));

        set("objects", ([
                FOOD_D("mantou") : 4
        ]));

        setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        object me = this_player();
        object ob;

        if (arg && (ob = present(arg)) && ob->id("man tou")){
                if ( !wizardp(me) && (present("man tou", me) || me->query("family/family_name")!="ؤ��"
                 || me->query("food") > me->query("str")*10 )){
                        write("�������и��Ͻл�����һ�����㲻�ɵ��������֡�\n");
                        return 1;
                }
        }
        return 0;
}