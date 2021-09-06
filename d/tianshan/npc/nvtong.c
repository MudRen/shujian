// Npc: /d/tianshan/npc/nvtong.c
// By Linux

#include <ansi.h>
inherit NPC;
int ask_tong1();

void create()
{
        set_name("Ůͯ", ({"nv tong", "tong", "girl"}));
        set("gender", "Ů��");
        set("per",25);
        set("age", 8);
        set("long", 
                "�������ΰ�С�����ԼĪ�а˾��꣬��˫Ŀ��磬����������������֮\n"
                "ʱ������һ�����˵����ϡ�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 40);
        set("dex", 40);

        set("inquiry", ([
                "ͯ��" : (: ask_tong1 :),
                "��ɽͯ��" : (: ask_tong1 :),
                "name" : (: ask_tong1 :),
        ]));

        set("qi", 8000);
        set("max_qi", 8000);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 9600);
        set("max_neili", 9600);
        set("eff_jingli", 4500);
        set("jiali", 100);
        set("combat_exp",4000000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hand",300);
        set_skill("strike", 300);
        set_skill("sword",300);

        set_skill("zhemei-shou",300);          //��ң��÷��(hand)
        set_skill("liuyang-zhang",300);        //��ɽ������(strike)(unarmed)
        set_skill("yueying-wubu",300);       //ƾ���ٷ�(dodge)
        set_skill("bahuang-gong", 300);        //�˻�����Ψ�Ҷ���(force)
	set_skill("tianyu-qijian", 300);     //��ɽ����(sword)
	set_skill("literate", 160);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");

        create_family("���չ�",1, "��ɽ��ʦ");
	setup();

        carry_object(MISC_D("cloth"))->wear();   
}

void init()
{
        add_action("do_ketou", "ketou");
}

int ask_tong1()
{
        object me=this_player(),ob=this_object();
        if (me->query_temp("tonglao/pass3")){
                command ("haha");
                message_vision(CYN"$N˵����������"+ RANK_D->query_rude(me) +"���۹⡣���˳���Ҳ���������û��ء�\n"
                        "����������������й�������һ�����������Ĺ���\n"NOR, ob);
                me->set_temp("tonglao/pass4",1);
                me->set_temp("tonglao/ketou",0);
                ob->set_name("��ɽͯ��", ({ "tianshan tonglao", "tonglao"}) );
                ob->set("nickname", HIR "Ψ�Ҷ���" NOR);
                ob->set("title", "���չ�����");
                ob->set("long",
	    		"�����ǡ����չ����Ŀ�ɽ��ʦ.\n"+
	    		"էһ���ƺ��Ǹ��˾����Ů��,������ȴ����������.˫\n"+
	    		"Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");
                return 1;
        } else {
                command ("?");
                command ("dunno");
                return 1;
        }
}

int do_ketou(string arg)
{
        object me=this_player();
        if (!me->query_temp("tonglao/pass4")) return 0; 

        if( !arg || arg != "tonglao" ) return 0;
        if( me->query_temp("tonglao/ketou") < 6 ){
                switch( random(2) ) {
                case 0:
                                message_vision("$N�ع��ؾ��ĶԶ���ɽͯ�ѿ��˸���ͷ��\n",me);
                                me->add_temp("tonglao/ketou",1);
                        break;
                case 1:
                                message_vision("$N˫�۽��գ���������������ɽͯ�ѿ��˸���ͷ��\n",me);
                                me->add_temp("tonglao/ketou",1);
                        break;
                }
                return 1;
        }
        if( me->query_temp("tonglao/ketou") >= 6 ) {
                message_vision(CYN"��ɽͯ�ѵ���������������ѹ�����������һ��Ҫ�������㣬�����ν��󱲣�\n"+
                        "�㴫����ɽ�����ƺ���ɽ��÷�֣����չ��ص�����������ƺ���÷�ֵ�Ҫ������\n"+
                        "����ȥ�������ص����߷��Ƕ������ߡ�����·һֱ���߿��Գ�ȥ������\n"NOR, me);
                me->set("quest/tonglao/pass", 1);
                me->set_skill("liuyang-zhang",10+random(5));
                me->set_skill("zhemei-shou",10+random(5));
                message_vision(HIC"�����ɽ�����ƽ����ˡ�\n", me);
                message_vision("�����ɽ��÷�ֽ����ˡ�\n"NOR, me);
                log_file("quest/tonglao",sprintf("%8s%-10s�ɹ��⿪ͯ�����ܣ����飺%d������%d��������%d��\n",
                        me->name(),"("+me->query("id")+")", me->query("combat_exp"),
                        me->query("kar"), me->query("quest/tonglao/quest")), me);
                me->delete_temp("tonglao");
                remove_call_out("dest");
                call_out("dest", 2, this_object());
                return 1;
        }
}

void dest(object ob)
{      
        if (!ob ) return;
        message_vision(YEL"\nͻȻ����������������٣����Ŷ�������������������ͷ��ȥ��������ʮƥ���۶�����\n"+
                            "���ϳ��߶����˵���ɫ����ԶԶ����������һƬ���ƣ����ü���Ů�������е�������\n"+
                            "��������׷�����٣��������������ʮƥ���۽�ǰ������ȫ��Ů�ӣ������ؿڶ�����һ\n"+
                            "ͷ���գ���̬��������Ů����ͯ�ѣ��㼴�����첽��������ͯ����ǰ�ݷ��ڵ����˶�ͯ\n"+
                            "�Ѽ��Ǿ�η�������ڵأ��������ӡ�ͯ�Ѻ���һ����ŭ���������Ƕ������Ѿ����ˣ��ǲ�\n"+
                            "�ǣ������ϸ��ڵ������ؿ�һ��ͷ��˵���������ң����¾���Ų���ȫ����ɽ����·ǰ��\n"+
                            "�ź��������������ܣ�׷�����٣���������������˵��������ͷ��ͯ�ѵ����������Ǹ���\n"+
                            "�������ã�����������֮�У�·������Ҳ���˵����ͷ���Ȼع�����˵�ɡ���˵���һ��\n"+
                            "�������չ������ȥ��\n"NOR, ob);
       destruct(ob);
}

#include "npc.h";
