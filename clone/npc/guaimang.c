inherit NPC;

void create()
{
    set_name("����", ({ "guai mang", "snake", "mang" }) );
	set("race", "Ұ��");
	set("age", 80);
    set("long", "һ���������������ߣ����������ġ�\n");
    set("attitude", "aggressive");
	
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "twist", "bite" }) );

	set("combat_exp", 12000);
set("no_get","�����������̫���������޷��ö�");
	
	set_temp("apply/attack", 355);
	set_temp("apply/defense", 350);
	set_temp("apply/damage", 350);
	set_temp("apply/armor", 350);

	setup();
}

 
