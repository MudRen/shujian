// ̫��ȭPFM
// by snowman@SJ
// Modify by snowman@SJ 27/02/2000

#include <ansi.h>

string exert_name(){ return HIG"̫����"NOR; }

int check_fight(object me);
int exert(object me)
{
	object weapon;
	
        if( !me->is_fighting() || !living(me))
                return notify_fail("��̫����ֻ����ս���е�ʹ�á�\n");
        if( me->query_temp("tj/̫��"))        
                return notify_fail("��̫����֮�����಻�������Ѿ��ڷ������������ˡ�\n");  
        if( (int)me->query("max_neili", 1) < 1200 )
                return notify_fail("���������Ϊ̫�������Ӳ�����̫���������ơ�\n");                
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("�������������������Ӳ�����̫������������\n");
        if( userp(me) && (int)me->query_skill("yinyun-ziqi", 1) < 100 )
                return notify_fail("����������ȼ������ߣ����Ӳ�����̫������������\n");
        if( userp(me) && (int)me->query_skill("taoism", 1) < 100 )
                return notify_fail("��Ե�ѧ�ķ������򲻹������Ӳ�����̫������Բת���ϵ����⡣\n");
        if( userp(me) && me->query_skill_mapped("force") != "yinyun-ziqi")
                return notify_fail("����ڹ����ԣ��������ܷ��ӳ���̫���������ơ�\n");                                                                                     
        if( userp(me) 
        &&( me->query_skill_mapped("parry") != "taiji-quan"
        && me->query_skill_mapped("parry") != "taiji-jian") )
                return notify_fail("��̫�������ϱ�������̫��ȭ��̫���������мܵ�����²���ʹ�á�\n");
        if( me->query_skill_prepared("cuff") != "taiji-quan"
        || me->query_skill_mapped("cuff") != "taiji-quan")
                return notify_fail("����붮��̫��ȭ������ʩչ��̫������\n");  
        if( me->query_skill_mapped("sword") != "taiji-jian" )
                return notify_fail("����붮��̫������������ʩչ��̫������\n"); 
                
        if( objectp(weapon = me->query_temp("weapon")) ){
        	if( weapon->query("skill_type") != "sword" )
                	return notify_fail("�����ʹ�ý��������á�̫������\n");
                if( (int)me->query_skill("taiji-jian", 1) < 150 )
                	return notify_fail("���̫������������죬��������ᡸ̫����֮���ϡ�\n");
                if( (int)me->query_skill("taiji-jian", 1) > 350 )
                	return notify_fail("���Ѿ���͸��̫��������������ʹ�á�̫���������ˡ�\n");
                
                if( me->query("jiali") && me->query_skill("taiji-jian", 1) < 300)
                	return notify_fail("��̫�����������ⲻ������̫��Բת����ʹ�Ͼ�����������������޷����ӳ����������ġ�\n");
          	if( me->query("jiali") > me->query_skill("taiji-jian", 1) / 3)
                	return notify_fail("Ϊ��ʹ̫�����ⲻ����֮����ȫ���ӣ��㲻����˼�����\n");
                message_vision("\n$N�����ƶ���һ�ֳֽ���һ�ֻ��˸���ָ������ֿ�ƽ�У���������������������ǰ�������������أ�ÿһ�ж�����̫��ʽ�������仯����΢���\n",me);
        	tell_object(me, CYN"\n��Ĭ���񹦣����Լ��ͽ��������һ����̫������"RED"�����⡹"CYN"���ӵ����쾡�£�\n\n"NOR);
        }
        
        else {      
        	if( (int)me->query_skill("taiji-quan", 1) < 100 )
                	return notify_fail("���̫��ȭ������죬��������ᡸ̫����֮���ϡ�\n");
        
        	if( (int)me->query_skill("taiji-quan", 1) > 350 )
                	return notify_fail("���Ѿ���͸��̫��ȭ��������ʹ�á�̫���������ˡ�");
                	
        	if( me->query("jiali") && me->query_skill("taiji-quan", 1) < 200)
                	return notify_fail("��̫�����������ⲻ������̫��Բת����ʹ�Ͼ�����������������޷����ӳ����������ġ�\n");
        
        	if( me->query("jiali") > me->query_skill("taiji-quan", 1) / 5)
                	return notify_fail("Ϊ��ʹ̫�����ⲻ����֮����ȫ���ӣ��㲻����˼�����\n");
                
        	message_vision("\n$N�����ƶ���˫���´����ֱ����⣬��ָ΢�棬����ֿ�ƽ�У���������������������ǰ����۰뻷��
������Գ����ƣ����Ʒ��������ƣ�����$P˫��Բת��ÿһ�ж�����̫��ʽ�������仯����΢���\n",me);
        	tell_object(me, CYN"\n��Ĭ���񹦣�˫����Ȼ�Ӷ����������һ����̫��ȭ"RED"��ȭ�⡹"CYN"���ӵ����쾡�£�\n\n"NOR);
        }
        
        me->start_busy(1);
        me->delete_temp("tj");
        me->set_temp("tj/̫��", 1);
        check_fight(me);
        return 1;
}

string check_force(object ob)
{
	string force;
	
	if(!stringp(force = ob->query_skill_mapped("force")))
       		force = "�ڹ�";
        
        switch(force){
        	case "yinyun-ziqi": break;
        	case "huntian-qigong":
        	case "hamagong":
        	case "longxiang-boruo": force = "�귭"; break;
        	case "huagong-dafa":
        	case "guiyuan-tunafa":
        	case "dulong-dafa": force = "����"; break;
        	case "yijin-jing":
        	case "bihai-chaoshen":
        	case "qiantian-yiyang":
        	case "kurong-changong": force = "����"; break;        	
        	case "shenyuan-gong":
        	case "zixia-gong":
        	case "shenghuo-shengong": force = "����"; break;        	
        	case "lingji-zhuang":
        	case "yunu-xinjing":
        	case "shenzhao-jing": force = "����"; break;
        	default: force = "����"; break;
        } 
        return force;
}
        
int check_fight(object me)
{    
	object ob, weapon;
	string force;
	
        if( !me || !me->query_temp("tj") ) return 0;
	
        if( me->is_ghost() || !living(me) || !me->query_temp("tj/̫��") ){
                me->delete_temp("tj");
                return 0;
        }                                
        
        weapon = me->query_temp("weapon");
        
        if( !me->is_fighting() || me->query("neili") <= 10){
        	if( !weapon )
                	message_vision(CYN "\n$Nʹ�������ơ�����̫������ǰ������ǰ�죬���ҷֿ�����΢���������ƽ���������������䣬�����е�վ�ڵ��ء�\n\n"NOR, me);
		else 	message_vision(CYN "\n$N��������ֹ��˫�ֱ�������ǰ���������䣬�����е�վ�ڵ��ء�\n\n"NOR, me);
                me->delete_temp("tj");
        } 
        
        if( weapon ){
        	if( weapon->query("skill_type") != "sword" ){
        		write(HIY"��һ��������̫��֮��㲻����ͨ�ˣ�\n"NOR);
        		me->delete_temp("tj");
        	}
        	else if( me->query_skill_mapped("sword") != "taiji-jian" ){
                	message_vision(CYN"$NͻȻ��̫������һ�գ���һһ�ֽ���������\n"NOR, me);
                	me->delete_temp("tj");
                }
                
                else if( (int)me->query_skill("taiji-jian", 1) < 150 ){
                	write(HIY"���̫������������죬��᲻�ˡ�̫����֮���ϣ�\n"NOR);
                	me->delete_temp("tj");
        	}
                else if( me->query("jiali") && me->query_skill("taiji-jian", 1) < 300 ){
                	write(HIY"��̫�����������ⲻ������̫��Բת����ʹ�Ͼ�����������������޷����ӳ����������ˣ�\n"NOR);
                	me->delete_temp("tj");
        	}
          	else if( me->query("jiali") > me->query_skill("taiji-jian", 1) / 3 ){
                	write(HIY"Ϊ��ʹ̫�����ⲻ����֮����ȫ���ӣ��㲻����˼�����\n"NOR);
                	me->delete_temp("tj");
        	}
        	else call_out("check_fight", 1, me, weapon);
        	
        	if( me->query_skill_mapped("parry") != "taiji-jian" )
        		me->map_skill("parry", "taiji-jian");
        }
        
        else {
        	if( me->query_skill("taiji-quan", 1) < 300 && me->query("jiali")){
        		message_vision(CYN "\n$NͻȻһ�䣬�������ң��͸ղ���ȫ������\n\n"NOR, me);
                	me->delete_temp("tj");
        	}                
        	else if( me->query("jiali") > me->query_skill("taiji-quan", 1) / 5 ){
        		message_vision(CYN "\n$NͻȻ˫�ֱ��˸�̫��ʽ��ԲȦ���ھ�������\n\n"NOR, me);
                	me->delete_temp("tj");
        	}                                
        	else if ( me->query_skill_mapped("cuff") != "taiji-quan" 
        		|| me->query_skill_prepared("cuff") != "taiji-quan" ){
                	message_vision(HIY"$Nʹ��һʽ̫��ȭ��ͻȻ���У���Ȼ����ȫ��ͬ��������\n"NOR,me);
                	me->delete_temp("tj");
                	me->start_busy(1);
        	}           
       		else{      
       			if( me->query_skill("taiji-quan", 1) > 200
       			&& objectp(ob = me->select_opponent()) 
       			&& random(me->query_int()) > ob->query_int()
       			&& !me->query_temp("tjq/"+ob->query("id"))
       			&& stringp(force = check_force(ob)) 
       			&& force != "yinyun-ziqi"){
        			tell_object(me, HIC"����һϸ�Ĺ۲죬������"+ob->name()+"�����ڹ�����ʵ������һת���˳�����"+force+"������\n"NOR);
        			me->set("env/���Ͼ�", force);
        			me->set_temp("tjq/"+ob->query("id"), random(me->query_int())+1);
        		}
        		if( me->query_skill_mapped("parry") != "taiji-quan" )
        			me->map_skill("parry", "taiji-quan");
        		call_out("check_fight", 1, me);
        	}
        }
       	return 1;
}       

int help(object me)
{
	write(HIM"\n��������̫������"NOR"\n");
	write(@HELP
	̫��֮�⣬��仯��ˣ�����Ϊһ�ᡣ����������򶮾����ɶ������׼���
	����Ȼ�������վã����ܻ�Ȼ��ͨ�ɡ�����������̫��ȭ�����ж����Դ���
	��ϡ�ÿ�����괿���������˻��ߣ��ʽ���Ϊ���ƣ�˫��֮��δ�����ѭ��
	������ȼ������Ժ�������ã���Ϊ�����������󣬷�������������
	
	Ҫ��	̫��ȭ�ȼ� 100 ���ϣ�
		(�ý�����̫�������ȼ� 150 ����)
		�������ȼ� 100 ���ϣ�
		��ѧ�ķ��ȼ� 100 ���ϣ�
		������� 1200 ���ϣ�
		���� 500 ���ϡ�
HELP
	);
	return 1;
}
