
inherit NPC;

void setup()
{
	::setup();
	set("no_quest",1);
	set("no_ansuan",1);
	set("no_bark",1);
}

void fight_ob(object me)
{
	me->remove_enemy(this_object());
	remove_enemy(me);
}

void kill_ob(object me)
{
	me->remove_killer(this_object());
	remove_killer(me);
	me->remove_enemy(this_object());
	remove_enemy(me);
}

void unconcious()
{
        say( "С����һ�������Ҳ����ˣ������Ӱ࣡��\n");
        say( "�����¥����������һ��С������˵����û���⣬�����Ұɡ���\n");
        say( "ǰһ��С��������ֵ��뿪�ˡ�\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
}

void die()
{
        unconcious();
}
