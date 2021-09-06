//by caiji@SJ

#include <ansi.h>
#include <command.h>

inherit F_SSERVER;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "������",
        "northwest":    "������",
        "southeast":    "���Ϸ�",
        "southwest":    "���Ϸ�",
        "up":           "����",
        "down":         "����",
        "out":          "����",
        "enter":        "����",
]);

int exert(object me, object target)
{
	object env, obj;
	int cost=50+random(100), i, n;
	int success, ap, dp,bool,bool2;
	string msg;
	string *dirs, target_dir, dest;
	mapping exit;

	seteuid(getuid());
	
	bool=(me->query("env/xiaoguo")) ? 1:0;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ���ʩչ��������\n");
                
        bool2=(userp(target))?me->query_skill("poison",1):0;
        
        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("�����ֶ�����ҪҪ�á�������\n");
        
        if( !living(target) || ! target->query("can_speak"))
                return notify_fail("�����ֶ�����ҪҪ�á�������\n");

	if( !me->is_fighting(target))
		return notify_fail("��û�к�"+target->query("name")+"����ս��������ʩչ��������\n");

	if(me->is_busy())
		return notify_fail("���������Թ˲�Ͼ������ʱ��ʩչ��������\n");

	if((int)me->query_skill("huagong-dafa") < 60 || (int)me->query_skill("force", 1) < 60)
		return notify_fail("����ڹ��ȼ�����������ʩչ��������\n");

        if( me->query("neili") < cost )
                return notify_fail("�������������\n");

	if((int)me->query("qi") < 50 )
                return notify_fail("�����Ѫ̫�٣�����û���㹻����ɢ����������\n");

	env = environment(me);
	exit = env->query("exits");

	if( !mapp(exit)){
	if(bool) return notify_fail("����û�г��ڣ����뽫"+target->query("name")+"�����Ƕ�ȥ��\n");
	else return notify_fail("����û�г��ڣ������ӵ��Ƕ�ȥ��\n");
	}

	dirs = keys(exit);
	n = sizeof(exit);
	i = random(n);
	dest = exit[dirs[i]];

	if( !undefinedp(default_dirs[dirs[i]]) )
                target_dir = default_dirs[dirs[i]];
        else
                target_dir = dirs[i];

	if(!(obj = load_object(dest)) )
		return notify_fail("�޷��ߣ�\n");

	me->add("neili", -cost);
	me->receive_damage("qi", 10);

	msg = HIB "$N���˻����䣬һ��紵��������˲�䲼���˶���\n" NOR;

	success = 1;
        ap = me->query_skill("force") + me->query_skill("huagong-dafa") + me->query_kar()+bool2;
        dp = me->query_skill("force") + me->query_skill("dodge") + target->query_kar();   
        ap *= me->query("combat_exp")*120/100000;
        dp *= target->query("combat_exp")/1000;    

        if( random(ap) < dp/3 ) success = 0;

	message_vision(msg, me, target);

	if(success==1) {
		if(bool){
		     if(!GO_CMD->main(target, dirs[i], 0)) success=0;
		}
		else if(!GO_CMD->main(me, dirs[i], 0)) success=0;// failed to go.
	}

	if(success == 1)
		if(bool){
			msg = HIC "������ֻ��һ����Ӱ��" + target_dir + "��ȥ��\n" NOR;
                        msg += HIY +target->name()+"��" + target_dir + "׷ȥ��\n" NOR;
                }
                else
                msg = HIR "$Nɢ���ġ����������$n����ʲô���á�\n" NOR;
        
	//add by caiji for add other function next time
	else {
//		if(bool)
		msg = HIR "$Nɢ���ġ����������$n����ʲô���á�\n" NOR;
//		else msg = HIC "������ֻ��һ����Ӱ��" + target_dir + "��ȥ��\n" NOR;
	}
	message_vision(msg, me, target);

	if(success == 1){
		if(bool){
		msg = HIR "ֻ��"+target->name()+"���˽������Ĵ�������ȴʲô��û���֡�\n" NOR;
               	message( "vision", msg, environment(target), ({target}));
		tell_object(target,"�㼱��ææ���˹������Ĵ�������ȴʲô��û���֡�\n");
		target->start_busy(1+random(2));
//		me->start_busy(1);
		return 1;
        	}else{
	        msg = HIR "ֻ��"+me->name()+"�������������˽�����\n" NOR;
               	message( "vision", msg, environment(me), ({me}));
		tell_object(me,"����š����������Σ�����ææ���˹�������\n");
		target->start_busy(1+random(2));
               	return 1;}
        }
        else {
//		me->start_busy(1);
		return 1;
	}
}
string exert_name(){ return HIB"����"NOR; }