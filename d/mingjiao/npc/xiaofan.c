// xiaofan.c С����
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("С����", ({ "xiao fan", "xiao", "fan" }) );
        set("gender", "����" );
        set("age", 34);
        set("long", "��λС������Ц���������æ��������ʱ�к������Ŀ��˽�����\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
            (["name": "/d/mingjiao/obj/book","number" : 15]),
            (["name": FOOD_D("jiudai"),"number" : 20]),
            (["name": FOOD_D("baozi"),"number" : 30]),
            (["name": FOOD_D("zhuhu"),"number" : 20]),
        }));
        setup();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch(random(2)){
          case 0:
          say(CYN"С����Ц�����˵������λ"+RANK_D->query_respect(ob)+"������ЪЪ�Ȱɡ�\n"NOR);
          break;
          case 1: 
          say(CYN"С��������ָ�����˵����λ"+RANK_D->query_respect(ob)+"������ɣ��ȼ���Ȫˮ���ʡ�\n"NOR);
          break;
        }
}
