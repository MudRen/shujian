// xxxy.c ��ɳ��Ӱ ������ӡ

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return HIY"������ӡ"NOR;}

int perform(object me, object target)
{
        string msg,newroomfile,tarid;
        object weapon = me->query_temp("weapon");
	object room,newroom;
	object * obj;
        int lvl,i,j,local=0;
	string* dir=({ "e","w","n","s","ne","nw","se","sw","u","d","eu","wu","nu","su", 
		       "ed","wd","nd","sd","out","enter" });
	string* ldir=({ "east","west","north","south","northeast","northwest","southeast",
			"southwest","up","down","eastup","westup","northup","southup", 
		        "eastdown","westdown","northdown","southdown","out","enter" });
	string* fdir=({ "����","����","����","�ϱ�","������","������","���Ϸ�","���Ϸ�",
                        "�Ϸ�","�·�","���Ϸ�","���Ϸ�","���Ϸ�","���Ϸ�","���·�","���·�",
			"���·�","���·�","���","����" });
	string* tdir=({ "����","����","�ϱ�","����","���Ϸ�","���Ϸ�","������","������",
                        "�·�","�Ϸ�","���·�","���·�","���·�","���·�","���Ϸ�","���Ϸ�",
			"���Ϸ�","���Ϸ�","����","���" });
	string lfx,ffx,tfx,* str;

	if( (lvl=(int)me->query_skill("hansha-sheying", 1)) < 120 )
                return notify_fail("��ĺ�ɳ��Ӱ������죬����ʹ��������ӡ��\n");
        if( (int)me->query_skill("dulong-dafa", 1) < 120 )
		return notify_fail("��Ķ����󷨹������㣬������������ӡ��\n");
        if (!weapon || weapon->query("skill_type") != "throwing")
                return notify_fail("�������޷�ʹ��������ӡ��\n");
        if( (int)me->query("neili") < 150 )
                return notify_fail("����������̫��������ʹ��������ӡ��\n");
	room=environment(me);
	if (room->query("no_fight"))
		return notify_fail("��׼������ս����\n");
	if (!me->query_temp("xydir",1)){
            if( !target ) target = offensive_target(me);
            if( !target
              || !objectp(target)
              ||  !target->is_character()
              ||  target->query("no_pk"))
               	return notify_fail("��Ҫ��˭��\n");
    	    else
		local=1;
	}
	else{
 	  for(i=0;i<sizeof(dir);i++)
 	     if(dir[i]==me->query_temp("xydir",1)) break;
	     if(i>=sizeof(dir)){
		tarid=me->query_temp("xydir",1);
		str=explode(tarid,"&");
		if(sizeof(str)>1){
 		  tarid=str[0];
		  for(i=1;i<sizeof(str);i++){
			tarid+=" ";
			tarid+=str[i];
 		  }
		}
		for(i=0;i<sizeof(ldir);i++){
 		  lfx=ldir[i];
		  if(room->query("exits/"+lfx)){
			newroomfile=room->query("exits/"+lfx);
			if(!objectp(newroom=find_object(newroomfile))) 
			continue;
 		        obj = all_inventory(newroom);
        		for(j=0;j<sizeof(obj);j++){
				string *ids = obj[j]->parse_command_id_list();
				if (member_array(tarid, ids) != -1) 
				break;
			}
			if(j<sizeof(obj)) break;
		  }
		}
		if(i>=sizeof(ldir))
			return notify_fail("��Ҫ��˭��\n");
		else{
			target=obj[j];ffx=fdir[i];tfx=tdir[i];
		}
	     }  
	     else{
		lfx=ldir[i];ffx=fdir[i];tfx=tdir[i];
		if(!room->query("exits/"+lfx))
		     return notify_fail("��Ҫ�������䣿\n");
		newroomfile=room->query("exits/"+lfx);
		if(!objectp(newroom=find_object(newroomfile))) 
		newroom=load_object(newroomfile);
		obj = all_inventory(newroom);
        	for(i=0;i<sizeof(obj);i++){
			if(me->is_killing(obj[i]->query("id")))	break;
		}
		if(i>=sizeof(obj))
               		return notify_fail("��Ҫ��˭��\n");
		target=obj[i];
	     }
             if(newroom->query("no_fight"))
		   return notify_fail("��������ȫ����������\n");
	}
	if(local == 1)	
        	msg = HIY "$Nʹ��һ�С�������ӡ������ʮö"+weapon->query("name")+"������·��һ·����$nǰ�أ���һ·�ɵ�$n����ͷ��������ġ�\n";
	else
		msg = HIY "$Nʹ��һ�С�������ӡ������ʮö"+weapon->query("name")+"������·������"+ffx+"\n";

        message_vision(msg, me, target);
	me->add("neili", -100);
        me->add("jingli", - 40);

	target->start_busy(1);
        me->start_busy(2+random(2));

	me->set_temp("xxxy",1);

	if(local==0){
	    me->move(newroom);
	    msg = HIY "��Ȼ��"+tfx+"����ʮö"+weapon->query("name")+"������·������$n!\n";
	    message_vision(msg, me, target);
	}
	else{
	    me->add_temp("apply/attack", lvl/5);
	}
      	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
      	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	if(local==0){
	    me->move(room);
	    me->delete_temp("xydir");	
	}
	else
		me->add_temp("apply/attack", -lvl/5);
	if(!me->is_fighting(target)){
	    me->fight_ob(target);
		if (userp(me) && userp(target))
			target->set_temp("other_kill/"+me->query("id"), 1);
	    target->kill_ob(me);
	}
      	me->delete_temp("xxxy");
      	me->start_perform(4,"������ӡ");
        return 1;
}
