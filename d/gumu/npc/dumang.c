// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
	set_name("����", ({ "du mang", "mang" }));
	set("race", "Ұ��");
	set("age", 20);
        set("long", "һ���Ӵ��ޱ�, ɫ�ʰ�쵵ľ���������������ǿ�ҵ��ȳ�ζ��\n");
	set("attitude", "aggressive");
	set("str", 70);
	set("con", 50);
	set("max_qi", 800);
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 200000);

	set_temp("apply/attack", 150);
	set_temp("apply/armor", 150);
	setup();
}
 
void die()
{
	int i;
	object ob;
	object me = query_temp("last_damage_from");
	object *inv;

if(!objectp(me))         {       destruct(this_object());
		return notify_fail("");
        }

	inv = deep_inventory(me);
	i = sizeof(inv);
	message_vision("\n$N�鴤�˼��£���������һ�����ˡ�\n", this_object());
	while (i--)
	if( inv[i]->query("drug") || !userp(me)){
		destruct(this_object());
		return notify_fail("");
	}
	ob = new(MEDICINE_D("neili/gshedan"));
	ob->set("owner", me->query("id"));
	message_vision("\n$N����ʰ����һ��$n��\n",me, ob);
	log_file("quest/neili",sprintf("%-18sɱ���������õ�%s��\n",
		me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
	ob->move(me);
	destruct(this_object());
}
