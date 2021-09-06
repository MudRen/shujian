// learn.c
// LinuX@SJ 2004/02/28
// update by lsxk@hsbbs  ����츳Ӱ��Ч��  2008/3/14

#include <ansi.h>
#include <job_mul.h>
#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�������㼸�£�ҡ��ҡͷ��\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, teacher, skill_name;
	object ob;
	int i = 1, j, k, l, m;
	int improve;
	int master_skill, my_skill, gin_cost;

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if (!arg ||
		(
			sscanf(arg, "%s %s %d", teacher, skill, i) != 3
			&& sscanf(arg, "%s from %s", skill, teacher) != 2
			&& sscanf(arg, "%s %s", teacher, skill) != 2
		)
	)
		return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����> [����]\n");


	if (me->is_fighting())
		return notify_fail("����ĥǹ������������\n");

	if (!(ob = present(teacher, environment(me))) || !ob->is_character() || ob->query("race") != "����")
		return notify_fail("��Ҫ��˭��̣�\n");

	if (ob->query("env/no_teach"))
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");	
		

	if (!living(ob))
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

	if (!master_skill = ob->query_skill(skill, 1))
		return notify_fail("���������±����ұ���ѧ�ˡ�\n");

	if (me->query("potential") < i || i < 1)
		return notify_fail("��û����ô��Ǳ����ѧϰ��û�а취�ٳɳ��ˡ�\n");

	if( i > 50 )
		return notify_fail("һ��ѧϰ��ô�࣬��û����һ�����ģ��ٵ�ɡ�\n");

	notify_fail(ob ->name() + reject_msg[random(sizeof(reject_msg))]);
	if (!me->is_apprentice_of(ob)
	&& !ob->recognize_apprentice(me)
	&& me->query("marry/id") != ob->query("id"))
		return 0;

	if ( me->query_skill(skill, 1) >= 220 && SKILL_D(skill)->type() == "martial")
		return notify_fail("��������Ѿ��޷�ͨ��ѧϰ������ˡ�\n");

	if (me->query("id") == ob->query("marry/id")) {
		notify_fail(ob->name()+"����ɫ�е��ѿ����ƺ��ǲ��봫������������\n");
		if (me->query_skill(skill, 1) > ob->query_skill(skill, 1) - me->query("divorce") * 20)
			return 0;
		if (SKILL_D(skill)->type2() == "worker")
			return 0;
		if (SKILL_D(skill)->valid_enable("force")
		&& me->query("family/family_name") != ob->query("family/family_name"))
			return 0;
	}

	notify_fail(ob->name() + "��Ը���������ܡ�\n");

	if (ob->prevent_learn(me, skill))
		return 0;

	my_skill = me->query_skill(skill, 1);
	if (my_skill >= master_skill)
		return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

	notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	if (!SKILL_D(skill)->valid_learn(me))
		return 0;

	m = me->query_int();
	gin_cost = (90 + random(10)) / m;

	if (!my_skill) {
		gin_cost *= 2;
                me->delete_skill(skill);
	}

	gin_cost += my_skill / 10;


	teacher = ob->name();
	if (i > 1)
		teacher += "����";

	write("����" + teacher + "����йء�" + to_chinese(skill) + "�������ʡ�\n");


 if(userp(ob))
         if(     skill == "hujia-daofa"      || skill == "miaojia-jianfa"    || skill == "lengquan-shengong"
              || skill == "qixian-wuxingjian"|| skill == "xixing-dafa" || skill =="kuihua-mogong"
              || skill == "xuanyin-jian"     || skill == "jiuyin-shenfa"     || skill == "jiuyin-shenzhua" 
              || skill == "yinlong-bian"     || skill == "jiuyin-baiguzhua"  || skill == "cuixin-zhang"
              || skill == "daode-jing"       || skill == "dafumo-quan"       || skill == "jiuyin-shenzhang"   
              || skill == "yangjia-qiang"    || skill == "qianzhu-wandushou" || skill == "jindao-heijian"     || skill == "ningxue-shenzhua"   
              || skill == "beiming-shengong" || skill == "lingbo-weibu"    
              || skill == "tianmo-gong" || skill == "hengshan-jianfa"    
              || skill == "huanmo-longtianwu" || skill == "piaomiao-shenfa"    
              || skill == "taishan-jianfa" || skill == "tianmo-dao"    || skill == "yeqiu-quan"
              || skill == "tianmo-gun" || skill == "tianmo-jian"    
              || skill == "tianmo-shou" || skill == "tianmo-zhang"    
              || skill == "tangshi-jianfa"   || skill == "shenzhao-jing"
              || skill == "jinshe-jianfa"    || skill == "jinshe-zhangfa"    || skill == "wudu-yanluobu" 
              || skill == "lingshe-quanfa"   || skill == "lingshe-zhangfa"   || skill == "hamabu"
              || skill == "kongming-quan"    || skill == "yingshe-shengsibo" || skill == "yuenu-jian"         || skill == "yitian-tulong"    
|| skill == "wudang-jiuyang" || skill == "zhemei-shou" || skill=="liuyang-zhang" || skill=="kongming-quan" ||skill=="jingmai-xue"
              || skill == "wuhu-duanmendao"  || skill == "pixie-jian"        || skill == "kuihua-shengong"    || skill == "dugu-jiujian"     || skill == "kuihua-mogong" )


        return notify_fail(ob->name()+"����ɫ�е��ѿ����ƺ��ǲ��봫������������\n");


	if (ob->query("env/no_teach"))
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

	gin_cost *= i;
	if (userp(ob)) {
		tell_object(ob, me->name() + "��������йء�" + to_chinese(skill) + "�������ʡ�\n");
		if (ob->query("jing") < gin_cost / 5 + 10) {
			write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲô��\n");
			tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
			return 1;
		}
		ob->receive_damage("jing", gin_cost/5 + 1);
	}

	if (!random(10))
		tell_room(environment(me), me->name() + "������" + ob->name() + "������⡣\n", ({ me, ob }));

	if (me->query("jing") > gin_cost + 10) {
		if ((SKILL_D(skill)->type()=="martial"
		||   SKILL_D(skill)->type2() == "worker")
		&& my_skill * my_skill * my_skill / 10 > me->query("combat_exp"))
			return notify_fail("Ҳ����ȱ��ʵս���飬���"+ob->name()+"�Ļش������޷���ᡣ\n");

		if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
			write("�㿪ʼ��ȡ"+teacher+"��ָ�����ԡ�"+skill_name+"����һ�н��п�˼��\n");
		else write("������"+teacher+"��ָ�����ƺ���Щ�ĵá�\n");
		
		if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") ){
			if (!random(5))
			write("������Լ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ���������Լ�ѧϰ�����°빦����\n");
			if (!random(10))
			tell_room(environment(me), me->name() + "���ڲ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ������" + ob->name() + "������⡣\n", ({ me }));
		}
		if (me->query("age") < 30) {
			l = (35 - me->query("age")) / 3;
			if (me->query("age") <= 20)
				l += l;
		}
		my_skill /= 10;
		for (k = 0;;) {
			j = random(m * 3 / 4) + random(my_skill) + m / 4;
			me->add("potential", -1);
			improve = j+l+random(++k);
			
			/*�������ƿ�ʼ*/
		        if (me->query("registered")==3)
		        {
				improve = improve * LEARN_MUL * VIP_LEARN_MUL /10000;
		        }
		        else
		        {
				improve = improve * LEARN_MUL /100;
		        }
		        /*�������ƽ���*/ 
		        if(me->worker_skill("highest")>350) improve = improve*7/10;
			else if(me->worker_skill("highest")>220) improve = improve*8/10;
			if(me->worker_skill("limit")>600) improve = improve*8/10;

                   //�츳��������š�Ӱ��Ч����  by lsxk@hsbbs 2008/3/14
                   if((int)me->query("relife/study/jsqc",1) > 0){
                       tell_object(me,HIG"��ֻ�����Լ��츳���ˣ�ѧϰ��������Զ���˼Ҹ߳���࣡\n"NOR);
                       improve += improve * (int)me->query("relife/study/jsqc",1) * 2 / 100;
                   }
		        
			if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") )
				me->improve_skill(skill, improve*2); // 2 ��
			else
				me->improve_skill(skill, improve);
			if (wizardp(me) && me->query("env/test"))
			write (sprintf("������Ϣ����������� %d �㣬�������� %d ��\n",improve*2,improve));
			
			if (k >= i)
				break;
			if (!me->is_apprentice_of(ob)
			&& !ob->recognize_apprentice(me)
			&& me->query("marry/id") != ob->query("id"))
				break;
			if (!SKILL_D(skill)->valid_learn(me))
				break;
			my_skill = me->query_skill(skill, 1);
			if (my_skill >= master_skill)
				break;
		}
	} else {
		gin_cost = me->query("jing");
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}

	me->receive_damage("jing", gin_cost);
	if (i > 1)
		me->add_busy(1);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : learn|xue <ĳ��> <����> [����]

���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

����xue master force 10  -> �� master ����ѧ 10 �� force

���У��������Ϊ 50����ÿ��ѧϰ���ԣ�������ıȴ����ٵĽ����ٶ��ж�������ӡ�

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

�������ָ�� : apprentice, practice, skills, study
HELP
	);
	return 1;
}


