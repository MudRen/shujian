// NPC: /d/chengdu/npc/liuhaoyi.c
// By Jpei

inherit NPC;

#define	BOOKNUM		4
#define	SHELFNUM	7
#define	RETRY		7

int ask_question();
int ask_rule();
int do_guess(string arg);
int do_list(string arg);

void create()
{
	set_name("������", ({ "liu haoyi", "liu" }));
	set("nickname", "��Ϯ�Ӿ�");

	set("gender", "����");
	set("age", 40);
	set("long", "��Ŀ�⾼�����������أ������书���͡�\n");
	set_skill("unarmed", 20);
	set_skill("dodge", 15);
	set_temp("apply/damage", 5);

	set("combat_exp", 5000);
	set("attitude", "peaceful");

	set("inquiry", ([
		"name": "��ѽ����һ��������Ϯ�Ӿ�����Ȼ�����˲�֪���ҵ����֣�",
		"rumors": "�����������ʧ�������ף��ñ�����н��������ϱ�ĶԾֵȣ����ǲ�֪���㶮����Χ�塣",
		"here": "�������ҵļң��뵱��������ʥ�����˸��Ӿ������������뷽��Ӿ�����",
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"��" : (: ask_question :),
		"question" : (: ask_question :),
		"����" : (: ask_rule :),
		"rule" : (: ask_rule :),
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_guess", ({"guess", "cai"}));
        add_action("do_list", ({"list", "lie"}));
	::init();
}

int ask_question()
{
	object me = this_player();
	int i, j, temp;
	string tempstr, result = "";

	if (me->query_temp("qipu_guess_win"))
		write("������Ц�����������ٽ�һ�Σ��ðɣ�����׼���þ����°ɡ���\n");
	else {
		write("�����ĵ�������Ŀ�������ģ�����һ��" + CHINESE_D->chinese_number(BOOKNUM) + "�ᡶ÷���ס������鷿����" + CHINESE_D->chinese_number(SHELFNUM) + "����ܣ�\n");
		write("�����Ұ���" + CHINESE_D->chinese_number(BOOKNUM) + "����ֱ�ŵ���ͬ�������ȥ����ֻ��³���ÿ��������Ǹ�����ϼ��ɡ�\n");
	}
	write("�����ĴҴ��߽��鷿����һ���ֳ����ˡ�\n");
	write("�����ĵ��ͷ���������ˣ�����(guess)�ɣ�Ҳ���������ҹ���(rule)����\n");
	for (i = 0; i < BOOKNUM; i++) {
		temp = random(SHELFNUM) + 1;
		tempstr = "" + temp;
		for (j = 0; j < i; j++) {
			if (tempstr == result[j..j]) {
				temp = random(SHELFNUM) + 1;
				tempstr = "" + temp;
				j = -1;
			}
		}
		result += tempstr;
	}
	me->delete_temp("qipu_guess");
	me->set_temp("qipu_guess/result", result);
	return 1;
}

int ask_rule()
{
	write("�����ĵ���������ܼ򵥣���ÿ����guess��������Ϊ�Ľ������\n");
	write("�����ĵ��������磬����Ϊ��һ���ڣ��ż��ϣ������ڣ��ţ������ڣ��ţ��Ĳ��ڣ��ţ��Ǿ�guess 2175����\n");
	write("�����ĵ������һ������ȫ�ԣ�ָ�¶����ĸ���ܷ����Ĳ�ģ�����ܶԣ�ָֻ�¶��ĸ���ܷ����û�в¶Էŵ����Ĳ�ģ��ĸ�������\n");
	write("�����ĵ�������������������ҷŵ�˳����һ���ڣ��ż��ϣ������ڣ��ţ������ڣ��ţ��Ĳ��ڣ��ţ���ô��Ӧ����1574����\n");
	write("�����ĵ�������¶ԣ��ż��������ᣬ��ʾ����һ��ȫ�ԣ�������¶ԣ��źͣ��ż������飬����û�¶����Ĳᣬ��ʾ���ж�����ܶԡ���\n");
	write("�����ĵ����������˰ɣ������˾Ϳ�ʼ��(guess)�ɡ���\n");
	write("�����ĵ�������ס����" + CHINESE_D->chinese_number(RETRY) + "�λ��ᡣ�������������ǰ�µĽ������ʱ������list���鿴�ġ���\n");
	return 1;
}

string justify_result(string result, string guess)
{
    int i, j, very_right = 0, right = 0;

	for (i = 0; i < BOOKNUM; i++) {
		for (j = 0; j < BOOKNUM; j++) {
			if (guess[i..i] == result[j..j]) {
				if (i == j) very_right++;
				else right++;
			}
		}
	}
	return "ȫ�Ե���" + CHINESE_D->chinese_number(very_right) + "����ֻ����ܶԵ���" + CHINESE_D->chinese_number(right) + "����\n";
}

int do_guess(string arg)
{
	object me = this_player();
	int i, j, times;
	string result, tempstr1, tempstr2;

	if (!(result = me->query_temp("qipu_guess/result"))) return 0;
	if (!arg) return notify_fail("��Ҫ��ʲô���Ľ����\n");
	if (strlen(arg) != BOOKNUM) return notify_fail("���Ǹ�����ֻ��" + CHINESE_D->chinese_number(BOOKNUM) + "������\n");
	for (i = 1; i < BOOKNUM; i++)
		for (j = 0; j < i; j++)
			if (arg[i..i] == arg[j..j])
				return notify_fail("���Ǹ�����ÿ���鶼���ڲ�ͬ����������𣿣�\n");
	me->add_temp("qipu_guess/times", 1);
	times = me->query_temp("qipu_guess/times");
	if (arg == result) {
		if (times < 5) {
			tempstr1 = "�����Ŀ����㣬���ȵص������������ֻ����";
			tempstr2 = "��";
		}
		else if (times < RETRY) {
			tempstr1 = "�����ĵ�ͷ������������ֻ����";
			tempstr2 = "��";
		}
		else {
			tempstr1 = "�����ĵ�������ܽ���ѽ��������";
			tempstr2 = "��";
		}
		write(tempstr1 + CHINESE_D->chinese_number(times) + "�λ���" + tempstr2 + "�³����ˡ���\n");
		me->delete_temp("qipu_guess");
		me->set_temp("qipu_guess_win", 1);
		write("��������ǽ�ϰ��˼��£����������ˣ�����Խ��鷿ȥ�ˡ���\n");
	}
	else {
		write("�����ĵ�������µ���" + arg + "��" + justify_result(result, arg));
		if (times < RETRY) {
			write("�����ĵ������㻹��" + CHINESE_D->chinese_number(RETRY - times) + "�λ��ᣡ��\n");
			me->set_temp("qipu_guess/guess" + times, arg);
		}
		else {
			write("������������˵��������汿��" + CHINESE_D->chinese_number(RETRY) + "�λ��ᶼû���У���Ӧ����" + result + "����\n");
			write("�����ĵ������´��ٲ°ɣ���\n");
			me->delete_temp("qipu_guess");
		}
	}
	return 1;
}

int do_list(string arg)
{
	object me = this_player();
	int i, times;
	string result;

	if (!(result = me->query_temp("qipu_guess/result"))) return 0;
	times = me->query_temp("qipu_guess/times");
	write("�����ĵ���������ǰ�µĽ�����£���\n");
	for (i = 1; i <= times; i++) {
		write("��" + CHINESE_D->chinese_number(i) + "�Σ���" + me->query_temp("qipu_guess/guess" + i) + "��" + justify_result(result, me->query_temp("qipu_guess/guess" + i)));
	}
	return 1;
}

