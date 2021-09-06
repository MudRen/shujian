// Room: /d/emei/jiudaoguai3.c ������ ��ʮ�ŵ���3

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIW "����" NOR);
        set("long", @LONG
һ���ȳ�֮�������������̧ͷһ������ʱë���Ȼ��һ����ڴ�ϸ�ľ�
�������������ϣ��ſ���ڣ���Ҫ����������
LONG
        );
        set("exits",([
                "down" : __DIR__"jiudaoguai3",
]));
        set("objects",([
        __DIR__"npc/jumang" : 1,
]));
        set("outdoors", "����ɽ");
        setup();
}

void reset()
{
        object room = this_object();
        object *ob;
        int i;
        
        ob = deep_inventory(room);
        if (!ob)
                return;
        for (i=0;i<sizeof(ob);i++)
        {
                if (userp(ob[i]) && !wizardp(ob[i]))
                {
                        tell_object(ob[i],"ͻȻ��һ��紵������֦ҡҡ�λΣ��㱻���䵽�����¡�\n");
                        ob[i]->move(__DIR__"jiudaoguai3");
                        tell_room(environment(ob[i]),"ͻȻ��һ��紵����"+ob[i]->name(1)+"�����ϵ���������\n",({ob[i]}));
                        continue;
                }
        }
        
        ::reset();
}

void init()
{
        add_action("do_action", "");
}

int do_action(string arg)
{
        object me = this_player();
        string action = query_verb();

        switch (action)
        {
                case "dazuo":
                case "exercise":
                case "tuna":
                case "lian":
                case "practice":
                case "du":
                case "study":
                case "respirate":
                        message_vision("$N�������ƣ�����������ͻȻһ����С�ģ������ϵ�����ȥ��\n",me);
                        me->move(__DIR__"jiudaoguai3");
                        tell_room(environment(me),"ͻȻ��һ��紵����"+me->name(1)+"�����ϵ���������\n",({me}));
                        return 1;
        }
        return 0;
}
