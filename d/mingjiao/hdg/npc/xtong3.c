// xtong3.c Сͯ

inherit NPC;
#include <ansi.h>
void greeting(object);
void init();
void create()
{
        set_name("Сͯ", ({ "xiao tong","xiao","tong" }) );
        set("gender", "����" );
        set("age", 13);
        set("long", "����һ�������Сͯ������һ�����£�һ���ɰ������ӡ�\n");
        set("shen_type", 1);
        set("combat_exp", 50000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude", "friendly");

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver",random(50));
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

string *foods=({
        FOOD_D("rice"),
        FOOD_D("miantang"),
        FOOD_D("qingcai")
});

void greeting(object ob)
{  
	object food;
	mapping fam;

	fam = ob->query("family");
        if( !ob || environment(ob) != environment() ) return;
        if( fam && fam["family_name"] == "����"){
             say(CYN"СͯЦ������˵������λ" + RANK_D->query_respect(ob)
             + "�����˰ɣ����ò͡�\n"NOR);
             food = new(foods[random(sizeof(foods))]);
             food->set("value",0);
             food->move(ob);
        }
        else 
          say(CYN"Сͯգգ�۾���Ц������˵������λ" + RANK_D->query_respect(ob)
             + "����ӭ�����������ͣ�����Ҫ͵��Ӵ��\n"NOR);
        return;
}
