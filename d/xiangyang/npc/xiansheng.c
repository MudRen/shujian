// xiansheng.c ˽������

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("˽������", ({ "sishu xiansheng", "xiansheng"}));
	set("long", "��λ������������һ���飬����ҡͷ���Զ���\n");
	set("gender", "����");
	set("age", 22);
	set("shen_type", 1);

	set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);

        set("combat_exp", 100000+random(1000));
	set_skill("literate", 50);
        setup();
        carry_object(ARMOR_D("changshan2"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

int recognize_apprentice(object ob)
{
        int money = 50, level = ob->query_skill("literate", 1);

        if (level > ob->query("int")*10){
                message_vision(CYN"\n$N����$n������һ�������������������ƣ����޷��ٽ��޸������ѧ���ˡ���\n"NOR, this_object(), ob);
                return 0;
        }

        if (level > 10) money = 100;
        if (level > 29) money = 500;
        if (level > 39) money = 1000;

        ob->delete_temp("mark/literate");
        switch (MONEY_D->player_pay(ob, money)) {
                case 0:
                case 2: return 0;
        }
        ob->set_temp("mark/literate", 1);
        return 1;
}
