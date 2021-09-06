// npc: /d/xingxiu/shangren.c

inherit NPC;
void create()
{
        set_name("��˹����", ({ "bosi shangren", "shangren", "trader" }));
        set("gender", "����");
        set("age", 40 + random(10));
        set("long", "һ���߱����۵Ĳ�˹���ˡ�������������¶���ƻ���Ц�ݡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 6000);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("blade", 40);
        set_skill("parry", 30);
        set_skill("dodge", 40);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
		"��˹���˶��㼷��һ���۾�\n",
		"��˹���˶���˵���������ɰͣ��º�Ĭ�����ذ����� ��û������\n",
                (: random_move :)
        }));
        carry_object(BINGQI_D("wandao"))->wield();
        carry_object(ARMOR_D("changpao"))->wear();
}
