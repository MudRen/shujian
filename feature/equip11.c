// equip.c
// Modify by snowman@SJ 22/02/2000
// Modify by augx@SJ 9/13/2001
// Modify by augx@SJ 10/15/2001

#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

int wear()
{
	object owner;
	mapping armor_prop, applied_prop;
	string *apply, type, canwear;

	// Only character object can wear armors.
	if (!environment()) return 0;
	if( !(owner = environment())->is_character()) return 0;

	// If already worn, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "armor_prop" defined.
	type = query("armor_type");
	if (!type || !mapp(armor_prop = query("armor_prop")))
		return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");

	if( owner->query_temp("armor/" + type) )
		return notify_fail("���Ѿ�������ͬ���͵Ļ����ˡ�\n");

	if(objectp(owner->query_temp("weapon")) && type =="hands")
		return notify_fail("����������������δ����ף�\n");//by Ciwei@SJ
		
	if( query("broken") ) return notify_fail("��������Ѿ����ˡ�\n");

               canwear = query("armor_mp/armor_prop/canwear");
        if ( canwear && owner->query("family/family_name") != canwear)
               return notify_fail("����˼�"+canwear+"����ԨԴ����ô��㴩�˼ҷ��Σ�\n");

	owner->set_temp("armor/" + type, this_object());
	apply = keys(armor_prop);
	applied_prop = owner->query_temp("apply");
	if( !mapp(applied_prop) ) applied_prop = ([]);

   for(int i = 0; i<sizeof(apply); i++)
       {  
         if(apply[i]!="canwear" && apply[i]!="skills")
		 {
                     if( undefinedp(applied_prop[apply[i]]) )
			applied_prop[apply[i]] = armor_prop[apply[i]];
		else
			applied_prop[apply[i]] += armor_prop[apply[i]];
                  }
         }
	owner->set_temp("apply", applied_prop);
if (query("armor_mp/armor_prop/skills"))  // �ж���װ
owner->add_temp("skills"+"/"+ query("armor_mp/armor_prop/skills"),1);  // ������ϼӱ��
	set("equipped", "worn");
	return 1;
}

int wield()
{
	object owner, old_weapon;
	mapping weapon_prop;
	string *apply;
	int flag;

	// Only character object can wear armors.
	if (!environment()) return 0;
	if( !(owner = environment())->is_character() ) return 0;

	// If already wielded, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "weapon_prop" defined.
	if (!query("skill_type") || !mapp(weapon_prop = query("weapon_prop")) )
		return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");
	if( owner->query_temp("armor/hands") )
		return notify_fail("�㴩���������ò������������ˡ�\n"); //by Ciwei@SJ
	if( query("broken") ) return notify_fail("��������Ѿ����ˡ�\n");
	flag = query("flag");

	if( flag & TWO_HANDED ) {
		if( owner->query_temp("weapon")
		 || owner->query_temp("secondary_weapon")
		 || owner->query_temp("armor/shield") )
			return notify_fail("�����ճ�˫�ֲ���װ��˫��������\n");
		owner->set_temp("weapon", this_object());
	} 
	else {
		// If we are are using any weapon?
		if( !(old_weapon = owner->query_temp("weapon")) )
			owner->set_temp("weapon", this_object());

		else // If we still have a free hand? 
		if( !owner->query_temp("secondary_weapon")
		 && !owner->query_temp("armor/shield") ) {
	
			// If we can wield this as secondary weapon?
			if(flag & SECONDARY) {
				owner->set_temp("secondary_weapon", this_object());
			// If we can switch our old weapon to secondary weapon ?
			} else if( (int)old_weapon->query("flag") & SECONDARY ) {
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();
			// We need unwield our old weapon before we can use this one.
			} else
				return notify_fail("������ȷ�����Ŀǰװ����������\n");

		// We have both hands wearing something.
		} else
			return notify_fail("�����ճ�һֻ����ʹ��������\n");
	}

	apply = keys(weapon_prop);
	for(int i = 0; i<sizeof(apply); i++)
		owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);
	
	owner->reset_action();
	set("equipped", "wielded");
	return 1;
}

int unequip()
{
	object owner;
	mapping prop, applied_prop;
	string *apply, equipped;

	if( !(owner = environment()) ) return 0;
	if( !stringp(equipped = query("equipped")) )
		//return notify_fail("��Ŀǰ��û��װ������������\n");
		return 1;//unequip success so return 1! for move()  by Ciwei@SJ

	if( equipped=="wielded" ) {
		if( (object)owner->query_temp("weapon") == this_object() )
			owner->delete_temp("weapon");
		else if( (object)owner->query_temp("secondary_weapon") == this_object() )
			owner->delete_temp("secondary_weapon");
		prop = query("weapon_prop");
		owner->reset_action();
	} else if( equipped=="worn" ) {
 
		owner->delete_temp("armor/" + query("armor_type") );  
		prop = query("armor_prop");
if (query("armor_mp/armor_prop/skills"))  // �ж���װ
owner->add_temp("skills"+"/"+ query("armor_mp/armor_prop/skills"),-1);  // ������ϼ����
	}

	apply = keys(prop);
	applied_prop = owner->query_temp("apply");
	if (!applied_prop) applied_prop = ([]);
	for(int i = 0; i<sizeof(apply); i++)
             { 
              if(apply[i]!="canwear" && apply[i]!="skills")
		applied_prop[apply[i]] -= prop[apply[i]];
              }
	// ��ȥ���

	delete("equipped");
	return 1;
}

int broken(string str)
{
	object victim = environment(this_object());
       object owner;
	if( query("no_broken") ) return 0;
	if( !mapp(query("weapon_prop")) && !mapp(query("armor_prop")) ) return 0;
	
	unequip();
        
	if( victim->is_character() ) {
		this_object()->move(environment(victim));
		if( mapp(query("weapon_prop")) ) victim->reset_action();
	}
        
	if(victim)
	{
		this_object()->delete_weapon2(victim);
		this_object()->delete_armor2(victim);
	}
		
	if( (int)query("imbued")>3 ) {
		delete("owner");
		destruct(this_object());
		return 1;
	}
		
	if( !str ) str = "�𻵵�";

	delete_temp("apply");
	delete("weapon_mp/owner");
	delete("armor_mp/owner");
	set_temp("apply/name_old", query("name"));
	set_temp("apply/weapon_prop_old", query("weapon_prop"));
	set_temp("apply/armor_prop_old", query("armor_prop"));
	set_temp("apply/long_old", query("long"));
	set_temp("apply/value", query("value"));
	set_temp("apply/weapon_mp_old",query("weapon_mp"));
	set_temp("apply/armor_mp_old",query("armor_mp"));
			
	set("name", str + query("name"));
	set("value", 49);
	set("broken", 1);
	set("weapon_prop", 0);
	set("armor_prop", 0);
	set("treasure", 0);
	set("long", (string)query("long")+"\n�������Ѿ��𻵣���Ҳ�޷�ʹ���ˡ�\n");
	
	delete("owner");
	delete("weapon_mp");
	delete("armor_mp");
	delete("armor_prop/canwear");
      delete("armor_prop/skills");

	return 1;
}

int do_embed(object me)
{
	object ob;
	ob = this_object();

	if( !ob->query("embedded") || !me) return 0;

	if(environment(ob) != me 
	|| me->is_ghost() 
	|| !me->query_temp("embed")){
		delete("embedded");
		return 0;
	}

	me->receive_wound("qi", ob->query("damage")*2, "����"+ob->name()+"��");
	me->receive_damage("qi", ob->query("damage")*4, "����"+ob->name()+"��");
	tell_object(me, HIR "��Ѫ��˳�������ϵ�"+ob->name()+HIR"�����વ�ֱ��������\n" NOR );
	tell_room(environment(me), HIR + "��Ѫ˳��"+me->name()+HIR"���ϵ�"+ob->name()+HIR"ֱ��������\n" NOR, ({ me }));  
	call_out("do_embed", 15+random(10), me);

	return 1;
}
