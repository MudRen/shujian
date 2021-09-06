
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name(HIY"Τ��֮��"NOR, ({ "weilan's hammer", "chui"}));
        set_weight(6000);
        if( clonep())
               set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long",@LONG
����Τ���������������ʽ�Ľ���������˹�����õ��������ɲ��ұ�С͵��ȥ��
LONG
               );
               set("value", 0);
               set("material", "steel");
               set("dazao_award",1);
               set("wield_msg", "$N����һ��$n��\n");
               set("unwield_msg", "$N�����е�$n���¡�\n");
        }
        init_hammer(20);
}

void init()
{
	add_action("do_fix",({"fix","xiu"}));
}

int do_fix(string arg)
{
	object me = this_player();
	object obj,weapon;
	int delay = 15 + random(30);
	
	if(environment(this_object())!=me) return 0;
		
	if (me->is_busy()) return notify_fail("����æ���أ�\n");
        if (me->is_fight()) return notify_fail("����æ���أ�\n");
        if (!arg) return notify_fail("��Ҫ��ʲô��\n");
        if ( !objectp(obj = present(arg, me)))
        	return notify_fail("������û������������\n");
        
        if ( !objectp(weapon=me->query_temp("weapon")) || weapon!=this_object() )
                return notify_fail("�����װ��"+name()+"������ά�ޱ�����\n");
                
        if(!mapp(obj->query_temp("apply/weapon_mp_old")) && (!mapp(obj->query("weapon_prop")) || !(int)obj->query("imbued") ) )
		return notify_fail(name()+"ֻ��ά�����������ı�����\n");
        if (!obj->query("broken") &&  obj->query("weapon_mp/dur") >= obj->query("weapon_mp/max_dur") )
                return notify_fail("����������������������\n");

	message_vision(HIY"$N��ʼ��ϸ��ά��"+obj->query("name")+HIY"����ʱ��"+name()+"���ô��......\n\n"NOR, me);        
	me->start_busy(delay);
	call_out("xiu_finish",delay*2-1,me,obj);
        return 1;
}


void xiu_finish(object me,object obj)
{
        int i;  
        if(!objectp(me) || !userp(me) || !objectp(obj) ) return;
        if(!this_object() ||  environment(this_object())!=me) return;        
	obj->delete("broken");
	obj->delete("treasure");
				        
        if(obj->query_temp("apply/weapon_mp_old")) obj->set("weapon_mp",obj->query_temp("apply/weapon_mp_old") );
	if(obj->query_temp("apply/name_old")) obj->set("name",obj->query_temp("apply/name_old"));
	if(obj->query_temp("apply/weapon_prop_old")) obj->set("weapon_prop",obj->query_temp("apply/weapon_prop_old"));
	if(obj->query_temp("apply/long_old")) obj->set("long",obj->query_temp("apply/long_old"));
	
	obj->delete_temp("apply");		
        message_vision(HIY"$N��ϸ��ά��"+obj->query("name")+HIY+"��������»ָ�������ԭò��\n"NOR, me);
        WORKER_D->check_impove(me,"duanzao",me->query_int()/2,2);
        
        i = obj->query("weapon_mp/max_dur");
        obj->set("dur",i);
        obj->set("weapon_mp/dur",i);
        obj->set("weapon_mp/max_dur",i);
                
        obj->set("weapon_mp/weapon_prop",copy(obj->query("weapon_prop")));
        obj->save_weapon(me);
        
        unequip();
        destruct(this_object());
}
