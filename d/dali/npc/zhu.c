// zhu.c ����

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("˽������", ({ "sishu xiansheng", "xiansheng"}));
        set("long", "��λ����������ҡͷ���Եض��顣\n");
        set("gender", "����");
        set("age", 65);

        set_skill("literate", 140);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);

        set("combat_exp", 500000);
        set("shen_type", 1);
        setup();
        carry_object(ARMOR_D("cloth"))->wear();

}

int recognize_apprentice(object ob)
{
        int money = 50, level = ob->query_skill("literate", 1);
	    int rate;
		/*
		��ҵ�literate�ȼ�����80ʱ��ѧϰ���ã�GOLD������Ϊԭ����50%��
		��ҵ�literate�ȼ�����80ʱ��ѧϰ���ã�GOLD���ָ��������㹫ʽ��
		��ҵ�literate�ȼ�����250ʱ��ѧϰ���ã�GOLD������Ϊԭ����150%��
		*/
        if (level > ob->query("int")*10){
                message_vision(CYN"\n$N����$n������һ�������������������ƣ����޷��ٽ��޸������ѧ���ˡ���\n"NOR, this_object(), ob);
                return 0;
        }
		rate=1;
		if(level > 80) rate=2;
		if(level > 250) rate=3;
		
		if (level > 29) money = 100*rate/2;
        if (level > 59) money = 500*rate/2;
        if (level > 89) money = 1000*rate/2;
        if (level > 119) money = 2500*rate/2;

        ob->delete_temp("mark/literate");
        switch (MONEY_D->player_pay(ob, money)) {
                case 0:
                case 2: return 0;
        }
        ob->set_temp("mark/literate", 1);
        return 1;
}
