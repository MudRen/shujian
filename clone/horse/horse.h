//Cracked by Roath
// horse.h for horse fainting when riding.
// RYU
// modified by aln 4 / 98

#include <ansi.h>
condition_check()
{
        object *ob, me = this_object();
        int my_jingli, my_mj, i, addjing;

        my_jingli  = (int)me->query("jingli");
	my_mj = (int)me->query("max_jingli");
	addjing = (my_mj - my_jingli)/2;

	if(!living(me)) return;

	if(my_jingli <=10){
	if (ob = me->query("rider")){
        ob->delete("rided");
        message_vision("$Nһͷ��$n������������������������\n", ob, me);
        ob->receive_wound("qi", 150, "��"+me->name()+"�ϵ�����ˤ����");
        }
        me->delete("rider");

    // modified by aln to let horses follow none after be faint
        me->set_leader(0);
        me->unconcious();
        return;
        }

        if(my_jingli <=30 && my_jingli > 20){
        say(me->name() +"ֻ�ڴ����������ؿ��ܲ����ˣ�\n");
	return;
        }

	if(my_jingli <= my_mj/3){
        say(me->name() +"��ڴ�ڵش��Ŵ�����\n");
        return;
        }
}
void init()
{
	object me=this_object();

	int my_jingli, my_mj, i, addjing;

	if( environment(me)->query("resource/grass") &&
	me->query("food") < (me->max_food_capacity())){
	my_jingli  = (int)me->query("jingli");
        my_mj = (int)me->query("max_jingli");
        addjing = (my_mj - my_jingli)/2;
	me->add("food", (int)me->max_food_capacity()/4);
	me->add("jingli", addjing);
	say(me->name() +"����ͷ�ڲݵ��ϳ��������\n");
	}	

	add_action("do_look", "look");
	add_action("do_ting", "ting");
        add_action("do_ting", "stay");
        add_action("do_fang", "fang");
        add_action("do_fang", "release");
	add_action("do_gen", "gen");
        add_action("do_gen", "come");
}
int do_look(string arg)
{
	object *inv;
        int i;

        inv = all_inventory(this_object());

	if (!id(arg)) return 0;

	if (!sizeof(inv)) return 0;
	
	printf(this_object()->query("long") + 
	COMBAT_D->eff_status_msg((int)this_object()->query("eff_qi")* 100 / (int)this_object()->query("max_qi")) + "\n" 
	+ "���������ţ�\n");
        for (i = 0; i < sizeof(inv); i++)
                printf("%s \n", inv[i]->short());
        return 1;
}
