#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "tie jiang", "tie",}));
        set("long", "�������ĺ�ˮ����Ц�����Ŀ�����,����ʱ������ڲ����ϵ�Ĩ���������\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        
        set("max_qi", 600);
        set("max_jing", 300);


        set_skill("parry", 60);
        set("vendor_goods", ({
           (["name": BINGQI_D("changjian"),"number":25]),
           (["name": BINGQI_D("sword"),"number":15]),
           (["name": ARMOR_D("armor"),"number":22]),
           (["name": BINGQI_D("blade"),"number":10]),
           (["name": BINGQI_D("duanjian"),"number":10]),
           (["name": BINGQI_D("panguanbi"),"number":20]),
           (["name": BINGQI_D("tiegun"),"number":10]),
           (["name": BINGQI_D("gangzhang"),"number":12])
        }));
        setup();
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������������ðɡ�\n");
                        break;
                case 1:
                        say( "�����ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}