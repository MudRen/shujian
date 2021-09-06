// dongjing.c ̫��ȭ������������
// by snowman@SJ 02/03/2000
// Modified by snowman@SJ 24/05/2001

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

#define TAIJI                "/kungfu/skill/yinyun-ziqi/taiji"

int is_pfm() { return 1;}
string perform_name(){ return HIR"������"NOR; }

int perform(object me, object target)
{ 
        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( userp(me) 
        &&( me->query_skill_mapped("parry") != "taiji-quan"
        && me->query_skill_mapped("parry") != "taiji-jian") )
                return notify_fail("������������������̫��ȭ��̫���������мܵ�����²���ʹ�á�\n");
        if( userp(me) && (me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill_prepared("cuff") != "taiji-quan") )
                return notify_fail("����ڹ���ȭ�����ԣ��������ܷ��ӳ����������������ơ�\n");  
        if( !me->query_temp("tj/̫��") && me->query_skill("taiji-quan", 1) < 300 )
                return notify_fail("̫��ȭ��Ҫ���ڶ�����Ӧ���������棬��û�����á�̫�������������ʹ�á�����������\n");
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("����������������ǿ��ʹ�á����������Ƿ��Ӳ������������ģ�\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     
        if( target->query_condition("no_exert") )
                return notify_fail("( �Է���Ϣ���ȣ��������Ѿ�����ʩ���ڹ��ˡ�)\n");
                        
        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
        int damage = 1, ap, dp;
        string msg, force, str;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 300 || me->query("jingli") < 100 || me->query_temp("weapon"))
                return 0;     
                
        if(intp(me->query_temp("tjq/"+target->query("id")) > 3))
                me->add_temp("tjq/"+target->query("id"), -3);
        else me->delete_temp("tjq/"+target->query("id"));
        
        str = (string)me->query("env/���Ͼ�"); 
        if(str != "�귭" && str != "����" && str != "����" && str != "����" && str != "����" && str != "����")
                str = "��";
                
        msg = MAG"\n$Nʹ��̫��ȭ��"RED"����������"MAG"�Ĺ���";
        
        if(me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill("yinyun-ziqi", 1) < 100){
                msg += "ͻȻһ�³嵽$n��ǰ��Ҫץס$n��\n"NOR;
                str = "��";
        }        
        
        else msg += "��֮��ϣ��޹��������������죬��$n��ס�Լ���˫�֣�\n"NOR;
        
        if(TAIJI->check_force(target) == str || me->query_skill("taiji-quan", 1) > 350)
                damage = 3;
       
        me->start_perform(4, "����������");

        if(!stringp(force = to_chinese(target->query_skill_mapped("force"))))
                force = "�ڹ�";
        
        if(wizardp(me) && (string)me->query("env/combat")=="verbose")
                tell_object(me, "Str = "+str+"��Force = "+force+"��Damage = "+damage+"\n");

	ap = me->query("combat_exp", 1) * (me->query_str(1) + me->query_int(1));
	dp = target->query("combat_exp", 1) * (target->query_str(1)+ target->query_dex(1));

	if (target->is_busy())
		dp -= dp/2;

	if ( random(ap + dp ) > dp ) {
		msg += HIY"$p����һЦ����Ҫ������$P���䣡\n"NOR;
		me->start_busy(2);
		target->add_busy(2);
		call_out("hurt", 2+random(2),  me, target, damage, str, force);  
	}
	else{
		msg += HIY"��$p�Ͼ��о����ԣ������˺�ſ���$P������\n"NOR;
	        me->start_perform(2, "����������");
		me->start_busy(random(2));
	}
	message_vision(msg, me, target);
        return 1;
}

int hurt(object me, object target, int damage, string str, string force)
{
        object weapon;
        string msg;
        int p, i;
        
        if( !me || !living(me) || me->is_ghost() || !me->is_fighting()) return 0;
        
        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || damage < 1
        || environment(target)!=environment(me) || !target)
                return 0;
        
        msg = MAG"\n̫���ߣ��޼���������֮��֣���֮��ϣ�";
        switch(str){
                case "�귭": msg += "$N˫��һ��������ס$n��̫��ȭ��"HIW"��"+str+"����"MAG"��Ȼ�忪"+force+"ʹ������$nһ�ͣ�˦�˳�ȥ��\n"NOR;break;
                case "����": msg += "$N����һ����ץס$n��"HIW"��"+str+"����"MAG"͸��$n�����"+force+"һŦ��ץ��$p�Ӽ米��˦�˳�ȥ��\n"NOR;break;
                case "����": msg += "$N��"HIW"��"+str+"����"MAG"һ�ͣ���ɢ��$p��"+force+"���պ�����$nҪ��������ʱһ��һ�ţ���$p�Լ�ˤ��һ�󽻣�\n"NOR;break;
                case "����": msg += "$N˫��һ�֣�����"HIW"��"+str+"����"MAG"����ײ$n����$p��"+force+"��������Ӧ��\n"NOR;break;
                case "����": msg += "$N˫�Ʋ�����ȫ��"HIW"��"+str+"����"MAG"�߶���һ���Ӿ��Ƶ���$n��"+force+"������$p���վ�����ȣ�\n"NOR;break;
                case "����": msg += "$N�����׼�����糵�֣�����"HIW"��"+str+"����"MAG"����$n��"+force+"һ�ͣ���$p�����ȣ�ȫ��������մ���\n"NOR;break;
                default: msg = MAG"\n$NͻȻ������ס$n˫��һ��һ������$p���ڹ�������\n"NOR;break;
        }    
        
        if (target->query("neili") <= 200){
                message_vision(msg, me, target);
                tell_object(target, "�㷢���Լ�������Ȼ�ݽߺľ��������޷��࿹�ˣ�\n");
                target->receive_damage("qi", (int)target->query("qi")+1, me);
                msg = RED"���$N���ֲ��������Լ��ľ������ͷ��Ŀѣ��ҡҡ��׹��\n"NOR;
                msg += damage_msg(target->query("max_qi"), "ˤ��") + "( $N"+status_msg(5)+" )\n"; 
                message_vision(msg, target, target);
                me->start_busy(random(2));
		return 1;
	}
        
	else if(me->query("neili")*3 < target->query("neili")) {
		me->start_busy(1+random(2));
		msg += HIR"����$p�����ۺ񣬾����ϵ���˳��һ�壬��$P��߲�������\n"NOR;   
		message_vision(msg, me, target);
		return 1;
	}

	p = (int)me->query_skill("force") + random(me->query_skill("force")*2) + random(me->query("max_neili")) / 2;
	target->receive_damage("qi", p, me);
	target->receive_wound("qi", p/2, me);
	target->receive_wound("jing", me->query_int(1)*2 + me->query_con(1)*2, me);
	msg += damage_msg(p, "ˤ��")+
	"( $n"+eff_status_msg((int)target->query("qi")*100/(int)target->query("max_qi"))+" )\n"; 
        
	message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ p+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ p+ WHT"���˺���\n"NOR); ;

	if(wizardp(me) && (string)me->query("env/combat")=="verbose") 
		tell_object(me, "Damage ="+p+"\n");

	if(random(2) == 1 && !wizardp(me)){
		if( !me->is_killing(target->query("id"))
		&& !target->is_killing(me->query("id"))
		&& !me->query("have_master")   // added by snowman
		&& target->query("qi")*2 <= target->query("max_qi")) 
			COMBAT_D->end_fight(me, target);
		return 1;
	}

	if(wizardp(me) && (string)me->query("env/combat")=="verbose") 
		tell_object(me, "Dongjing done.\n");
                
	force = target->query_skill_mapped("force");

	switch(force) {
		case "huntian-qigong":
			if( intp(p = target->query_temp("htqg/powerup")) ){
				target->add_temp("apply/armor", - p*2);
				target->add_temp("apply/dodge", - p);
				target->delete_temp("htqg/powerup");
				tell_object(target, HIR"��Ļ���������һ����ɢ��ֻ�ý������ջص��\n"NOR);
				break;
			}
		case "yijin-jing":
			if( intp(p = target->query_temp("jingang_armor")) ){
				target->add_temp("apply/armor", - p);
				target->delete_temp("fanzhen");
				target->delete_temp("no_skill_hit_ob");
				target->delete_temp("jingang_armor");
				tell_object(target, HIR"��ġ���ղ������񹦡���һ����ɢ��ЧӦҲ��Ӧ����ʧ�ˣ�\n"NOR);
				break;
			}
		case "jiuyang-shengong":
			if( intp(p = target->query_temp("jiuyang/powerup")) ){
				target->add_temp("apply/armor", - p);
				target->add_temp("apply/dexerity", -p/2);
				target->delete_temp("jiuyang");
				target->delete_temp("no_skill_hit_ob");
				tell_object(target, HIR"��ġ������񹦡���һ����ɢ��ЧӦҲ��Ӧ����ʧ�ˣ�\n"NOR);
				break;
			}
		case "linji-zhuang":
			if( target->query_temp("ljz/riyue") ){
				target->delete_temp("ljz/riyue");
				tell_object(target, HIR"��ġ����¡�ׯ��һ����ɢ���������֮������ɢ������֮�䣡\n"NOR);
				break;
			}
			if( intp(p = target->query_temp("ljz/yinyang")) ){
				target->add("max_qi", - p);
				target->receive_wound("qi", p, "��������ׯ���ƣ�������");
				target->delete_temp("ljz/yinyang");
				tell_object(target, HIR"��ġ�������ׯ��һ����ɢ��������ЧӦҲ��ʧ�ˣ�\n"NOR);
				break;
			}
			if( intp(p = target->query_temp("ljz/fengyun")) ){
				target->add_temp("apply/dexerity", - p);        
				target->delete_temp("ljz/fengyun");
				tell_object(target, HIR"��ġ����ơ�ׯ��һ����ɢ���Ծ����ĳ�����һЩ��\n"NOR);
				break;
			}
			if( target->query_temp("ljz/wuwo")){
				target->delete_temp("ljz/wuwo");
				tell_object(target, HIR"��ġ����ҡ��ķ���һ����ɢ���ָֻ���ԭ�����㣡\n"NOR);
				break;
			}
		case "yinyun-ziqi":
			if( target->query_temp("tj/̫��") ){
				target->delete_temp("tj/̫��");
				tell_object(target, HIR"���ڻ�æ֮�У�̫������������У�ЧӦҲ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "dulong-dafa":
			if( intp(p = target->query_temp("sld/wudi2") ) ){
				target->add_temp("apply/attack", - p);
				target->add("max_qi",- target->query_temp("sld/wudiqi"));
				target->add_temp("apply/armor", -target->query_temp("sld/wudi"));
				target->delete_temp("sld");
				if(target->query("eff_qi") > target->query("max_qi")) 
					target->set("eff_qi", target->query("max_qi"));
				tell_object(target, HIR"����⡸��������һ������һ�ɣ���Ҳ֧�ֲ�ס�ˣ���\n"NOR);
				if(random( target->query("qi")) < 100) 
					target->unconcious();
				break;
			}
			else if( intp(p = target->query_temp("sld/wudi")) ){
				target->add("max_qi",- target->query_temp("sld/wudiqi"));
				target->add_temp("apply/armor", -p);
				target->delete_temp("sld/wudiqi");
				target->delete_temp("sld/wudi");
				if(target->query("eff_qi") > target->query("max_qi")) 
					target->set("eff_qi",target->query("max_qi"));
				tell_object(target, HIR"����⡸��������һ������һ�ɣ�����������һ����ͻȻ������������\n"NOR);
				break;
			}
		case "hanbing-zhenqi":
			if ( intp(p = target->query_temp("hbzq/huti")) ){
				target->add_temp("apply/parry", -p);
				target->add_temp("apply/dodge", -p);
				target->delete_temp("hbzq/huti");
				tell_object(target, HIR"����⡸��������һ������ĺ���ɢ�����������𵽱����������ˡ�\n"NOR);
				break;
			}
			if( target->query_temp("ss/focus")){
				target->delete_temp("ss/focus");
				tell_object(target, HIR"����⡸��������һ������ĺ���������ɢȥ�ˡ�\n"NOR);
				break;
			}
			if( target->query_temp("ss/hb")){
				target->delete_temp("ss/hb");
				tell_object(target, HIR"����⡸��������һ�����ϵĺ���������ɢȥ�ˡ�\n"NOR);
				break;
			}
		case "huagong-dafa":
			if( intp(p = target->query_temp("hgdf/judu")) ){
				target->add_temp("apply/armor", -p);
				target->delete_temp("hgdf/judu");
				tell_object(target, HIR"����⡸��������һ������һ�ɣ����۶���ȫ�����ˣ���\n"NOR);
				break;
			}
			else if( intp(p = target->query_temp("hgdf/huadu")) ){
				target->add_temp("apply/dodge", -p); 
				target->add_temp("apply/armor_vs_force", -p/2);           
				target->delete_temp("hgdf/huadu");
				tell_object(target, HIR"����⡸��������һ������һ�ɣ��������۶���ȫ�����ˣ���\n"NOR);
				break;
			}
		case "yunu-xinjing":
			if( target->query_temp("gm/xinjing") ){
				p  = target->query_temp("gm/xinjing");
				target->add_temp("apply/intelligence", -p/10);
				target->add_temp("apply/dexerity", -p/10);
				if ( target->query_skill("yunu-xinjing", 1) > 200 ){
					target->add_temp("apply/armor_vs_force", -p/5);
					if ( target->query("gender") == "Ů��") {
						target->add_temp("apply/dodge", -p/5);
						target->add_temp("apply/parry", -p/5);
						target->add_temp("apply/armor", -p/5);
					}
				}
				target->delete_temp("gm/xinjing");
				tell_object(target, HIR"��ġ��ľ����־�������ɢ��ЧӦҲ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "shenyuan-gong":
			if ( intp(p = target->query_temp("shenyuan")) ){
				target->add_temp("apply/parry", -p/3);
				target->add_temp("apply/dexerity", -p/5);
				target->delete_temp("shenyuan");
				tell_object(target, HIR"����⡸��������һ�𣬷�����ʽ�Ѿ������ˡ�\n"NOR);
				break;
			}
		case "xuantian-wuji":
			if ( target->query_temp("kl/riyue")){
				target->delete_temp("kl/riyue");
				tell_object(target, HIR"����⡸��������һ����ǰ����ǽ����С��������ʧ�����Ρ�\n"NOR);
				break;
			}
			if ( intp( p = target->query_temp("kl/taxue")) ) {
				target->add_temp("apply/dodge", -p);
				target->delete_temp("kl/taxue");
				tell_object(target, HIR"�����˽Ų������ظ���������\n"NOR);
				break;
			}
		case "longxiang-boruo":
			if ( intp(p = target->query_temp("xs/shield")) ) {
				target->add_temp("apply/dodge", -p);
				target->add_temp("apply/armor", -p*2);
				target->delete_temp("xs/shield");
				tell_object(target, HIR"�㱻����������һ�����Ϻ��һ�����ǽ�žž���켸����ɢȥ�˻���������\n" NOR);
				break;
			}
			if ( intp(p = target->query_temp("xs/longxiang")) ) {
				target->add_temp("apply/attack", -p);
				target->delete_temp("xs/longxiang");
				tell_object(target, HIR"�㱻����������һ����������һ�����ָֻ��糣��\n" NOR);
				break;
			}
		case "qiantian-yiyang":
			if( intp(p = target->query_temp("dali_jing")) ){
				target->add_temp("apply/intelligence", -p);
				target->delete_temp("dali_jing");
				tell_object(target, HIR"�㱻����������һ���޷�����Ǳ���ˡ�\n" NOR);
				break;
			}
		case "guiyuan-tunafa":
			if ( intp(p = target->query_temp("tz/focus")) ){
				target->add_temp("apply/attack", p);
				target->add_temp("apply/damage", p/2);
				target->delete_temp("tz/focus");
				tell_object(target, HIR"�㱻����������һ�𣬾�����Щί�٣������漴�ָ���̬��\n"NOR);
				break;
			}
		case "kurong-changong":
			if( intp(p = target->query_temp("pf_ku")) ){
				target->delete_temp("pf_ku");
				target->add_temp("apply/armor", -p/2);
				target->add_temp("apply/parry", -p/4);
				tell_object(target, HIR"�㱻����������һ�𣬡��ݡ��ִ�������ɢ�ˣ�\n" NOR);
				break;
			}
			else if( intp(p = target->query_temp("pf_rong")) ){
				p = target->query_temp("pf_rong");
				target->delete_temp("pf_rong");
				target->add_temp("apply/strike", -p/4);
				target->add_temp("apply/damage",-p/5);
				tell_object(target, HIR"�㱻����������һ�𣬡��١��ִ�������ɢ�ˣ�\n" NOR);
				break;
			}
		case "bihai-chaosheng":
			if ( intp(p = target->query_temp("thd/maze")) ){
				target->add_temp("apply/armor", - (p/4));
				target->delete_temp("thd/maze");
                                if(weapon = target->query_temp("thd/maze_target") && weapon = target->query_temp("thd/mazed")){
					weapon->delete_temp("thd/mazed");
					weapon->add_temp("apply/dexerity", p/10);
					weapon->add_temp("apply/dodge", p/10);
					weapon->add_temp("apply/damage", p/10);
					tell_object(weapon, target->name() + "���㲼�������Ѿ���"+me->name()+"�ġ�����������ɢ�ˡ�\n");
				}
				tell_object(target, HIR"�㱻����������һ�𣬲�������˲����ɢ�ˣ�\n" NOR);
				break;
			}
	}
	i = random(me->query_skill("taiji-quan", 1)/20);
	if( i < 5) i = 5;
	if( i > 15 ) i = 15;
	target->apply_condition("no_exert", i);
	if( !me->is_killing(target->query("id"))
	&& !target->is_killing(me->query("id"))
	&& !me->query("have_master")   // added by snowman
	&& target->query("qi")*2 <= target->query("max_qi")) 
		COMBAT_D->end_fight(me, target);
	return 1;
}

int help(object me)
{
	write(WHT"\n̫��������������"NOR"\n");
	write(@HELP
	̫��ȭ��������֮��֣���֮��ϡ��޹��������������졣�����׼������
	���֣�ƫ�����棬˫�����͡�����������һ�Ծ��ƶ����Զ��ƾ�֮���У���
	�����ֽ�ǰ���Ż����ƣ������ܴ��˶��֣�������Ч���Ƴ��Է��ĸ����ڹ���
	
	Ҫ��	���� 1000 ���ϣ�      
		���� 200 ���ϣ�      
		����̫��ȭ�������ޱ�����
HELP
	);
	return 1;
}
