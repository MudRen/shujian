// by xiaoyao

inherit NPC;

void create()
{
        set_name("����", ({ "hu li", "fox", "hu" }) );
        set("race", "Ұ��");
        set("age", 4);
       set("unique", 4);
        set("long", "һֻ���ɳ��Եĺ��ꡣ\n");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 10000);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 300);

        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "�������Ų��Ų�����ǽ䱸�����顣\n",
                "������Ŷ��ɵ��۹���㿴��ȫ��һ���ܽ��ŵ�ģ����\n",
        }) );
}

