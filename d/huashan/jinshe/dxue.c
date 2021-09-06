// Room: /d/huashan/jinshe/dxue.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","����");
        set("long", @LONG
���Ż��۹������㿴������ʯ����б����һ�����ù�(haigu )����ǰ��� 
�����˷���ʮ���ѽ���׶��ʯ�������ż��ٷ�����ͼ�Σ�ÿ������״������ͬ��
���������������䡣ͼ�ξ�����ʯ���ϳ����˼�����(zi)��Ҳ�������������ơ�
�аѽ���(sword)͹����ʯ��֮�ϡ� 
LONG                           
        );
        set("valid_startroom", 0);

        set("he_count",1);
        set("sword_count", 1);
        set("xia_count",1);
        set("haigu",1);
       
        set("item_desc", ([
                "haigu" : "�����·��������߰˳ɣ���Ȼ�пɼ����Ǹ����Ρ�\n",
                "zi": "�ر�������������Ե����������������ĪԹ��\n",
                "sword":"һ�ѱ���ֱ����ʯ��֮�У�ֻʣ�������Ľ�����\n",
        ]));
        set("objects",([
                __DIR__"obj/haigu" : 1,
//                BINGQI_D("throwing/jinshe-zhui") : 1,
        ]));
        setup();
}

void init()
{
        object me = this_player();
        add_action("do_zang", ({"zang","zang"}));
        add_action("do_shenzang", ({"shenzang","shenzang"}));
        add_action("do_ba", ({"pull","ba"}));
        add_action("do_pa", ({ "climb", "pa" }));
        me->set("startroom", "/d/city/guangchang");
}
 
int do_ba(string arg)  
{
        object sword,me;
        me = this_player();
        if ((int)me->query_temp("quest/jsj/fail",1) > 0)
          return notify_fail("����ʱ������ؼ���Ե�ˣ���ʱ�仹�ǿ�ȥ�����ɡ�\n");
//ʧ�ܺ�need login
  if ( !arg || arg != "bing" )
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if ( (int)query("sword_count") < 1)
          return notify_fail("��������ȥ�ν������Ƿ��ֽ��Ѿ�û���ˡ�\n");
        if((int)me->query_str() < 30)
                return notify_fail("�����˰���������Ҳ�޷��γ�������\n");    
        if( (int)me->query("neili") < 2000  ) 
                return notify_fail("����ס������������Σ����Ǳ�����˿������\n");
        if(random(10)!=6) {
                me->add("neili",-200);
                        return notify_fail("��ץס������΢һ������ֻ���ý�����΢���һ�¡�\n"); 
        }
        message_vision("$N������ס������Ǳ���������͵�һ���죬�ѽ����˳�����\n", me);
        add("sword_count", -1); 
        me->add("neili", -1000);
        me->set_temp("mark/sword",1);
        sword = unew(BINGQI_D("sword/jinshesword"));
        if(!clonep(sword)){ 
                message_vision("���$N�γ��˰���������������������ڵ��ϣ�ˤ�÷����ˡ�\n", me);
                me->delete_temp("mark/sword");//by yueying ��jsj quest����Ҫ���н��߽�
                
                return 1;
        }
        sword->move(me);
              
        return 1;
}

int do_shenzang(string arg)
{ 
        object xia;
        object me;
        
        int i;
        me = this_player();
        i = (int)me->query_temp("zang_nb");
        //if (!i) return 0;
        if (!( present("tie chu", this_player())))
                return notify_fail("̫���ˣ�����������ڣ�\n");
        if ( !arg || arg != "haigu" )
                return notify_fail("��Ҫ����˭��\n");
        if (!(int)me->query_temp("mark/zang"))
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if ( (int)me->query("quest/jsj/pass") > 0 && query("xia_count") > 0){
                message_vision("$N���ְѿ������˼��ߣ��õ�һ����ϻ(tiexia),���������˺��ǡ�\n",me);
    add("haigu", -1);
                add("xia_count", -1);
                xia=new(__DIR__"obj/tiexia");
                xia->move(me);
                me->set_temp("mark/shenzang",1);
                me->add("jingli",-200);
                me->delete_temp("zang_nb");
                destruct(present("skeleton", this_object()));
                return 1;
        }
             
  if ( i > 50 || query("xia_count") < 1 ){
        add("xia_count", -1);
        add("haigu", -1);
        me->add_temp("quest/jsj/fail",1);
        message_vision("$N���ְѿ������˼��ߣ�û�з����κζ������������������ã�ת���뿪�˶�Ѩ��\n",me);
        me->delete_temp("zang_nb");
if (present("skeleton"))         destruct(present("skeleton", this_object()));
        me->move(__DIR__"biding",);
    return 1;
  }
        if(random(8) != 3 || !random(3)) {
                me->add("jingli",-200);
                me->add_temp("zang_nb",1);
                return notify_fail("��ѿ�����������Ҳ��֪��������\n"); 
                                }
        if (random(2) > 0 ) {
                message_vision("$N���ְѿ������˼��ߣ����������ã�ͻȻ����һ����ϻ(tiexia)��\n",me);
    add("haigu", -1); 
                add("xia_count", -1);
                xia=new(__DIR__"obj/tiexia");
                xia->move(me);
                me->set_temp("mark/shenzang",1);
                me->add("jingli",-200);
                me->add("quest/jsj/pass",1);
                destruct(present("skeleton", this_object()));
        }
        else
                message_vision("$N�����������ڣ���Ȼ�Ѿ������ڹ��ˡ�\n", me);
                me->delete_temp("zang_nb",1);
                me->add_temp("quest/jsj/fail",1);
        return 1;
}

int do_zang(string arg)
{      
        object he;
        object me;
        me = this_player();          
        if (!( present("tie chu", this_player())))
                return notify_fail("����������ڣ���\n");
        if ( !arg || arg != "haigu" )
                return notify_fail("��Ҫ����˭��\n");
        if (!(int)me->query_temp("mark/sword"))
          return notify_fail("���ﲻ������£��㻹��ȥŬ�������ɡ�\n");
        if (query("haigu") != 1)
          return notify_fail("�������˭��\n");
        if (query("he_count") > 0) {
                message_vision("$N��������Ȼ�������밲��������ã����������ͷ��\n"+
                                "�������ȥ��û�ڼ��£�ͻȻ����һ��������(tiehe)��\n", me);
                add("he_count", -1);
                he=new(__DIR__"obj/datiehe");
                me->set_temp("mark/zang",1);
                me->add("jingli", -200);
                he->move(__DIR__"dxue",);
        }
        else
                message_vision("$N�����������ڣ������ƺ��Ѿ������ڹ��ˡ�\n", me);
        return 1;
}
 
int do_pa(string arg)
{
        object me;

        me=this_player();
        if ( !arg || arg != "up" )
                return notify_fail("��Ҫȥ���ģ�\n");
        if (!( present("kuang", this_player())))
                return notify_fail("����ʲ������ȥ����\n");
        message_vision("$Nץס������΢һ������������ȥ��\n", me);
        me->move(__DIR__"biding");
        tell_room(environment(me), me->name() + "ץס����,΢һ����,������ȥ��\n", ({ me }));
        me->delete_temp("mark/shenzang");
        return 1;
}

