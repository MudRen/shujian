// vote command..
// Improved by YUJ@SJ, 2000-11-11

#include <ansi.h>

inherit F_SAVE;

string query_save_file()
{
	return "/log/vote";
}

void create() {
	seteuid(getuid());
	restore();
}

int remove()
{
	save();
	return 1;
}

mapping vote=([
	"time":	0,
	"valid": 0,
	"desc": "",
	"num": 0,
	"choice": ([
		"1": "ͬ��",
		"2": "����"
	]),
	"votes": ([
		"ͬ��": 0,
		"����": 0
	]),
	"total": 0
]);

void set_vote()
{
	write("���ڿ�ʼ����ͶƱ���ݣ�������ʱ���������ȡ��\n");
	write("������ͶƱ��������");
	input_to("get_desc");
}

void get_desc(string desc)
{
	mapping ch = ([]);

	if (desc == "") return;
	write("�����빩ѡ������ݣ�. ��ʾ����\n1��");
	input_to("get_choice", ch, 1, desc);
}

void get_choice(string arg, mapping ch, int i, string desc)
{
	if (arg == "") return;
	if (arg == ".") {
		vote=([
			"time":	time(),			// �����ټ�ָ��ʱ�䣬lazy yuj 2000-11-11
			"valid": time() + 86400*3,
			"desc": desc,
			"num": i-1,
			"choice": ch,
			"votes": ([]),
			"total": 0
		]);
		save();
		return;
	}
	ch[""+i] = arg;
	write(++i+"��");
	input_to("get_choice", ch, i, desc);
}

void show_vote()
{
	int t = time(), i;
	string item;

	write(sprintf("%40s%d\n", "�Ѿ��յ���Ч��ѡƱ����", vote["total"]));
	for (i = 1; i <= vote["num"]; i++) {
		item = vote["choice"][""+i];
		write(sprintf("%40s%-4d%4d%%\n", "ѡ�� " HIG + item + NOR " ��Ʊ����",
			vote["votes"][item], vote["votes"][item]*100/vote["total"]));
	}
	if (t < vote["valid"])
		write(sprintf("%40s", "����ͶƱ��������"+chinese_number((vote["valid"]-t)/60)+"����\n"));
}

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name;
	string file;
	object file_ob;
	int t = time();
	int i, exp = me->query("combat_exp"); // * !wiz_level(me);
	string item;

	if (me->is_busy()) return notify_fail("����æ���ء�\n");
	if (me->query("age") < 16 && !wizardp(me))
		return notify_fail("�������Ƕ�Ϸ��С����һ����ȥ��\n");

	if (me->query("vote/deprived") && me->query_condition("vote_suspension"))
		return notify_fail("�����𵱳���Ū������������ͶƱȨ���£�׷��Ī����\n");

	if (!arg) {
		if (!vote["time"]) return notify_fail("Ŀǰû����ҪͶƱ�����ݡ�\n");
		write(sprintf("\n%40s" HIW "%s\n" NOR, "ĿǰͶƱ�����ݣ�",  vote["desc"]));
		if (t < vote["time"]) return notify_fail("ͶƱ��δ��ʼ");
		show_vote();
		me->set_temp("votes", vote["time"]);
		if (t > vote["valid"]) return notify_fail("ͶƱ�Ѿ�ֹͣ��\n");
		if (me->query("votes") > vote["time"]) return notify_fail("���Ѿ�Ͷ��Ʊ�ˡ�\n");
		if (exp < 500000) return notify_fail("��Ŀǰ��û��ͶƱ�ʸ�\n");
		if (!vote["num"]) return 1;
		me->start_busy(1);
		write("����Բ��μ�ͶƱ����������ѡ��\n");
		for (i = 1; i <= vote["num"]; i++)
			write("vote " + i + " ��ʾ��" HIG + vote["choice"][""+i] + NOR "\n");
		write("Ʊһ��Ͷ���Ͳ��ܸ��ģ����Լ�ע�⡣\n");
		return notify_fail("����ʥ��һƱ��Ҫ������˲���Ͷ��\n");
	}

	if (arg == "set") {
		if (wiz_level(me) < 5) return 0;
		set_vote();
		return 1;
	}
	if (arg == "remove") {
		if (wiz_level(me) < 5) return 0;
		vote=([
			"time":	0,
			"valid": 0,
			"desc": "",
			"num": 0,
			"choice": ([
				"1": "ͬ��",
				"2": "����"
			]),
			"votes": ([
				"ͬ��": 0,
				"����": 0
			]),
			"total": 0
		]);
		save();
		return 1;
	}

	if (sscanf(arg, "%d", i)) {
		if (me->query_temp("votes") < vote["time"]) {
			write("�㻹û��ͶƱ���ݾ�ͶƱ��I ���� You��\n");
			i = 2;
		}
		if (exp < 500000) return notify_fail("��Ŀǰ��û��ͶƱ�ʸ�\n");
		if (t < vote["time"]) return notify_fail("ͶƱ��δ��ʼ");
		if (t > vote["valid"]) return notify_fail("ͶƱ�Ѿ�ֹͣ��\n");
		if (i < 1 || i > vote["num"]) return notify_fail("���� vote ��ϸ�Ķ�ͶƱ˵����\n");
		if (me->query("votes") > vote["time"]) return notify_fail("�㲻���Ѿ�Ͷ��Ʊ����\n");
		item = vote["choice"][""+i];
		write("\n��� " HIW + vote["desc"] + NOR " ѡ���� " HIW + item + NOR "\n");
		vote["votes"][item]++;
		vote["total"]++;
		me->set("votes", t);
		if (!(vote["total"] % 5)) save();
		show_vote();
		return 1;
	}

	if (sscanf(arg, "%s %s", act_name, victim_name) != 2)
		return notify_fail("����ʥ��һƱ��Ҫ������˲���Ͷ��\n");

	victim = LOGIN_D->find_body(victim_name);
	if (!victim || !me->visible(victim))
		return notify_fail("��ҪͶ˭��Ʊ��\n");
	if (wizardp(victim))
		return notify_fail("��ûȨ������ʦͶƱ!\n");
	if( !stringp(file = (string)"/cmds/std/vote/"+act_name)
   	|| file_size(file + ".c") <= 0 )
		return 	notify_fail("��ҪͶƱ��ʲô��\n");

	if ( !(file_ob = find_object(file)) ) file_ob = load_object(file);

	if ((int)file_ob->vote(me, victim) <= 0) {
		if ((int)me->query("vote/abuse")> 50) {
			write( HIG "����Ϊ����ͶƱ��ͶƱȨ�������ˣ�\n" NOR);

			me->set("vote/deprived", 1);
			me->apply_condition("vote_suspension", 120);
			me->delete("vote/abuse");
		}
		return 0;
	};

	return 1;
}

int valid_voters(object me)
{
	object *list;
	int d = 0;
	int j;

    list = users();
    j = sizeof(list);
    while( j-- )
	{
		// Skip those users in login limbo.
        if( !environment(list[j]) ) continue;
        if( !me->visible(list[j]) ) continue;
		if (((int)list[j]->query("age")<16) && !wizardp(list[j])) continue;
		if ((int)list[j]->query("vote/deprived")) continue;

		d++;
	}

	return d;
}


int help(object me)
{
write(@HELP
ָ���ʽ : vote <����> <ĳ��>

�����������ĳ�˲�ȡ�ж����ɴ��ͶƱ��������������������û���˸��飬
ͶƱ���Զ�ȡ������ǰ����������<����>��

chblk:   �ر�ĳ�˽�̸Ƶ����
unchblk: ��ĳ�˽�̸Ƶ����
��������ĳ�ض��¼�ͶƱ��Ҫ���������ʮ��

HELP
    );
    return 1;
}
