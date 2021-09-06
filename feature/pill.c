// pill.c
// snowman 15.12.98
/*
���ļ�β���� inherit F_PILL

 ҩ�������set("healup", "...") ��ҩ������á����磺
    set("healup", ([
	"add_neili": 2000,
	"add_jingli": 2000,	
	]));

 �� set("drug_msg", ([
	   "start_eat": "$N����һ������ɢ��\n",
           "finish_eat": "$N����ɫ������ʼ��ת�ˡ�\n",
      ]));

 �������У�heal_eff_qi��heal_eff_jing���ȵȡ�
 ����no_fight����ʾfightʱ���ܳ�����ҩ
 CONDITION_EAT ��������ҩ����ɵĺ��������������� #define :), ���磺
      #define CONDITION_EAT me->add("neili", -100)

���õ��ǣ���� inherit F_PILL;  ��������ļ�β���������ļ�ͷ��

*/

#ifndef CONDITION_EAT
#define CONDITION_EAT me->add("neili", -100)
#endif

#include <ansi.h>
#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_eat", "fu");
}
int do_drug(string key, mixed i)
{
        switch(key) {
             case "heal_eff_qi": if ((int)this_player()->query("eff_qi") < (int)this_player()->query("max_qi"))
                             this_player()->receive_curing("qi", i); break;
             case "heal_eff_jing": if ((int)this_player()->query("eff_jing") < (int)this_player()->query("max_jing"))
                             this_player()->receive_curing("jing", i); break;
             case "add_jingli": this_player()->add("jingli", i); break;             
             case "add_neili": this_player()->add("neili", i); break;
             case "add_max_jingli": this_player()->add("max_jingli", i); break;
             case "add_max_neili": this_player()->add("max_neili", i); break;
             case "food": this_player()->add("food", i); break;
             case "water": this_player()->add("water", i); break;
             case "clear_all_condition": this_player()->clear_condition(); break;
             case "clear_type": this_player()->clear_conditions_by_type(i); break;
             case "apply_condition": this_player()->apply_condition(i); break;
             case "del_temp": this_player()->delete_temp(i); break;
             case "del": this_player()->delete(i); break;
             case "add_str": this_player()->add_temp("apply/strength", i); break;
             case "add_dex": this_player()->add_temp("apply/dexerity", i); break;
             case "add_int": this_player()->add_temp("apply/intelligence", i); break;
             case "add_con": this_player()->add_temp("apply/constitution", i); break;
             case "add_damage": this_player()->add_temp("apply/damage", i); break;
             case "add_attack": this_player()->add_temp("apply/attack", i); break;
        default: break;
        }
    return 1;
}
int do_eat(string arg)
{
	mapping healup, msg;
        object me, ob;
        string *key;
        int i;
        me = this_player();
        ob = this_object();

        if(!this_object()->id(arg) || !living(this_player())) return 0;
	if(me->is_busy() )
		return notify_fail("����æ���ء�\n");
        if(!mapp(healup = ob->query("healup")) )
		return notify_fail("�����������ܷ��á�\n");
        if(query("no_fight") )
                return notify_fail("��ս���г�ҩ�к����棡\n");	
        
        msg = ob->query("drug_msg");

	if (!msg || undefinedp(msg["start_eat"]))
                message_vision("$N����һ"+ob->query("unit")+"$n��\n", me, ob);
        else
                message_vision(msg["start_eat"], me, ob);

        if((int)query("condition") && me->query_condition("medicine") > 0){
                if (!msg || undefinedp(msg["condition_eat"]))
                       message_vision(HIR"$N������ҡҡ��׹��ԭ����������ҩ����ҩ�Թ��ͣ�\n"NOR, me, ob);
                else   message_vision(msg["condition_eat"], me, ob);
                CONDITION_EAT;
                return 1;
                }
        key = keys(healup);
        i = sizeof(key);
        while(i--) do_drug(key[i], healup[key[i]]);

        if (!msg || undefinedp(msg["finish_eat"]))
                EMOTE_D->do_emote(me, "stuff");
        else    message_vision(msg["finish_eat"], me, ob);

        if((int)query("condition"))
                me->apply_condition("medicine", query("condition"));
        if(query("busy_time")) 
                me->start_busy(query("busy_time"));
        else me->start_busy(1);
        if(ob->query_amount()) ob->add_amount(-1);
        else destruct(ob);
	return 1;
}


