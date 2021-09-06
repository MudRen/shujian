//wanglaohan  ���Ϻ�

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_me(object who);

void create()
{
	set_name("���Ϻ�", ({ "wang laohan", "wang"}));
	set("long", "����һ��ͷ�����׵���ͷ��æ�ſ��ձ���ͷҲ��̧��\n");
        set("gender", "����" );
        set("age", 58);
	set("shen", 1000);

	set("str", 35);
        set("int", 15);
        set("con", 15);
        set("dex", 20);

	set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);

        set("jingli",800);
        set("eff_jingli",800);
        set("jiali", 1);   
	set("combat_exp", 9000);

	set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("strike", 30);
        set_skill("parry", 30);

        set("inquiry", ([
                  "���ͨ"   : (: ask_me :),
	]) );

        set("vendor_goods", ({
            (["name": FOOD_D("shaobing"),"number" : 20]),
            (["name": FOOD_D("youtiao"),"number" : 30]),
            (["name": FOOD_D("mhbianzi"),"number" : 30]),
        }));

	setup();
	carry_object("/clone/misc/cloth")->wear();
        add_money("silver",5);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string ask_me(object who)
{
        int i;
        object *ob;

        if( query("revealed") ) {
                if( is_killing(who) ) return "���Ȼ֪�����ӵ����֣��͸ö�������Щ���������ɣ�\n";
                else {
                        kill_ob(who);
                        who->fight_ob(this_object());
                        return "��Ȼ��ˣ����ӽ��췴�����ȥ������ƴ�ˡ�\n";
                }
        }

        if( (random(10) < 5) || is_fighting() )
                return "����˭������\n";

        set_temp("apply/attack",  80);
        set_temp("apply/defense", 60);
        set_temp("apply/damage",  30);

        message("vision",
		HIR "���ͨŭ��˵�����������������������������վ�Ȼ���������ϳ��ˡ�\n"
		"���ͨ���һ�������ֻҪ���������µ��ˣ��������������������������\n" 
		"���ͨ�ӱ���ȡ��һ���йٱ��������С�\n" NOR,
		environment(), this_object() );
	set_name("���ͨ",({ "wu daotong", "wu", "daotong" }));
        set("pursuer", 1);
        set("vendetta/authority", 1);
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        carry_object("/d/tiezhang/obj/bi")->wield();
        carry_object(FOOD_D("shaobing"));
        carry_object("/clone/medicine/jugeng");
        carry_object("/clone/medicine/jugeng");

        set("bellicosity", 10000);
        set("combat_exp", 600000);
        set("qi", 2600);
        set("max_qi",2600);
        set("max_neili",2800);
        set("eff_jingli",2800);  
        set_skill("force", 150);
        set_skill("guiyuan-tunafa", 150);
        set_skill("dodge", 100);
        set_skill("shuishangpiao", 150);
        set_skill("strike", 150);
        set_skill("tiezhang-zhangfa", 120);
        set_skill("brush", 150);
        set_skill("yingou-bifa", 150);
        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "yingou-bifa");
        map_skill("brush", "yingou-bifa");
        ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
		if((int)ob[i]->query("combat_exp",1)<180000) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	add_money("gold", 1);
	set("revealed", 1);
	return "�ߣ����������ͨ�ڵĵط������˶�������\n";
}
