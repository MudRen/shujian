// ���аٱ�
// by augx@sj  10/3/2001

#include <ansi.h>
#include <command.h>
inherit F_SSERVER;

//int perform(object me, object target)
int main(object me, string arg)
{
	string msg;
	object target;
	string *exits, *kexits;
	int lvl,lvl2,k,a,b; 
	object room,oroom,lastroom,ob;
	
	if(!me->query_skill("youlong-shenfa",1))
		return 0;
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if( !me->is_fighting() )
		return notify_fail("�����аٱ䡹ֻ����ս��ʱ�ã�\n");
	//if( !arg ) 
	target = offensive_target(me);
	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target))
		return notify_fail("�����аٱ䡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("youlong-shenfa", 1) < 100 )
		return notify_fail("�������������������������ʹ�ã�\n");

	if(me->query_skill("dulong-dafa",1) < 100 )
		return notify_fail("��Ķ����󷨹������㣬�����á����аٱ䡹��\n");

	if(me->query_skill_mapped("force") != "dulong-dafa" )
		return notify_fail("��û�м��������󷨣�����ʹ�á����аٱ䡹��\n");

	if((int)me->query("neili") < 300)
		return notify_fail("�������������㣬�����á����аٱ䡹��\n"); 

	if((int)me->query("jingli") < 100)
		return notify_fail("�����ھ������㣬�����á����аٱ䡹��\n"); 

	if(userp(me) && (int)me->query_temp("sld/baibian") )
		return notify_fail("���Ѿ�ʹ�á����аٱ䡹�ˣ�\n"); 

	if(!me->query("quest/baibian"))
		return notify_fail("�㻹û����ᡸ���аٱ䡹��\n");

	msg = HIY"\n$N��ͻȻ�ӿ죬��Ӱ��翲����������޷�׷�٣�\n"NOR;

	message_vision(msg, me);
	me->add("neili",-300);
	me->add("jingli",-100);
	me->set_temp("sld/baibian",me->query("dex"));
	me->add_temp("apply/dexerity",me->query("dex"));
	
	lvl = me->query_skill("dodge") + 1;
	lvl2 = target->query_skill("dodge") + 1;
	if ( target->is_busy() || random(lvl*3/2+lvl2)>lvl2 ) {
		message_vision(HIY"$N�ɿ�����˿�ȥ��$n�����޷�ʶ��$N���ܵ�·����ֻ�ܴ����Ŀ���$N���ߣ�\n"NOR, me, target);
		me->start_perform(3,"�����аٱ䡹");
		foreach (ob in all_inventory(environment(me))) {
			if(!ob || ob==me || !me->is_fighting(ob) || ob->query_leader()!=me) continue;
			ob->set_leader(0);
		}
		me->remove_all_killer();
		
		room = environment(me);
		if( mapp(room->query("exits")) && sizeof(room->query("exits"))>0 ) {
			oroom = room;
			lastroom = room;
			for(k=0;k<9;k++) {
				exits = values(room->query("exits"));
				kexits = keys(room->query("exits"));
				b = sizeof(exits);
				while( (a=random(b))>=0 && b>1 ) {
					if (b==2)
						if ((exits[0]==base_name(lastroom) && exits[1]==base_name(oroom))
						 || (exits[1]==base_name(lastroom) && exits[0]==base_name(oroom)))
							break;
					if (exits[a]==base_name(lastroom) || exits[a]==base_name(oroom)) continue;
					break;
				}
				if( exits[a]!=base_name(oroom) || k<8 )
					GO_CMD->main(me,kexits[a]);
				lastroom = room;
				room = environment(me);
			}
		}
		
		if(room == oroom)
			message_vision(CYN"����$Nȴ������·���ӣ�\n"NOR, me);			 
        }
        else {
		message_vision(CYN"$N��ͼ���ߣ�����$nȴʶ����$N���ܵ�·�ߣ���$N����������\n"NOR, me, target);
		me->start_perform(2,"�����аٱ䡹");
	}

	call_out("remove_effect", 6, me);	
	return 1;       
}

void remove_effect(object me)
{
	if( !me || !me->query_temp("sld/baibian") ) return;
	me->add_temp("apply/dexerity", -me->query_temp("sld/baibian"));
	me->delete_temp("sld/baibian");
	message_vision(CYN"\n$N���ٱ�����һ�����ڲ���ά���������ٶȣ���������������\n"NOR, me);
}

//string perform_name(){ return HIY"���аٱ�"NOR; }
int help(object me)
{
	write("\n�����������аٱ䡹��\n\n");
	write(@HELP
        ��ս���п�������ս������ʹ�����޷�׷�٣��˱���֮�������С�
        Ҫ��100�������󷨣�100��������
              300������100����

HELP
	);
	return 1;
}
