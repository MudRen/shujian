inherit F_SAVE;
#include <ansi.h>
#define PRICE 20000
#define DUR 10800

string query(string arg)
{
	if (arg == "channel_id")
		return "ΤС��(Wei Xiaobao)";
}

string query_save_file()
{
	return "/data/lottery";
}

int t;

void remove()
{
	t = find_call_out("kaijiang");
	save();
}

void create()
{
	seteuid(getuid());
	restore();
	if (t)
		call_out("kaijiang", t < DUR?t:DUR);
	else
		call_out("finish", 1);
}

int generation = 1;
int last_award;
int award, no1;
int count1, award1, c1;
int count2, award2, c2;
int count3, award3, c3;

mapping total = ([
]);
int flag;

private number(int num)
{
	return chinese_number(num/1000%10)+chinese_number(num/100%10)
	+chinese_number(num/10%10)+chinese_number(num%10);
}

void purchase(mixed me, int num, int qty)
{
	if (!objectp(me))
		return;
	if (flag) {
		tell_object(me, "���ڿ������ȵȰɡ�\n");
		return;
	}
	if (qty < 1) {
		tell_object(me, "�������ţ�\n");
		return;
	}
	if (qty > 10000 || !me->query("lottery/"+generation+"/"+num) && sizeof(me->query("lottery/"+generation)) > 9) {
		tell_object(me, "�����������˰ɡ�\n");
		return;
	}
	if (num < 0 || num > 9999) {
		tell_object(me, "��ѡ����λ����(0000-9999)��\n");
		return;
	}
	switch (MONEY_D->player_pay(me, PRICE*qty)) {
		case 0:
		case 2:
			tell_object(me, "�����Ǯ������\n");
			return;
	}
	me->add("lottery/"+generation+"/"+num, qty);
	me->save();
	total[num] += qty;
	award += qty*PRICE;
	save();
	message_vision(
		sprintf("$N��%s�Ų�Ʊ��д�¡�"+HIW+"%s"+NOR+"���ĸ����֣�Ȼ�󽻸����С�ĵ��պá�\n",
			chinese_number(qty), number(num)
		), me
	);
}

private int check(int n1, int n2)
{
	string tmp1 = sprintf("%04d", n1), tmp2 = sprintf("%04d", n2);
	int i, k = 0;

	for (i = 0; i < 4; i++)
		k += tmp1[i] == tmp2[i];
	return k;
}

void show_now(mixed me)
{
	int i, n;
	mapping tmp, tmp2;

	if (!objectp(me))
		return;
	if (flag) {
		tell_object(me, "���ڿ������ȵȰɡ�\n");
		return;
	}
	tmp = me->query("lottery");
	if (!sizeof(tmp)) {
		tell_object(me, "��Ŀǰû���κβ�Ʊ��\n");
		return;
	}
	tell_object(me, "��Ʒ��˷���Ʊ�ǼǱ���˵��������\n");
	foreach (string gen in sort_array(keys(tmp),0)) {
		tmp2 = tmp[gen];
		if (!sizeof(tmp2))
			continue;
		if (atoi(gen) < generation-1 || atoi(gen) > generation) {
			tell_object(me, "һЩ���ڵĵ�"+chinese_number(atoi(gen))+"�ڲ�Ʊ������������ˡ�\n");
			map_delete(tmp, gen);
		} else
			foreach (string num in sort_array(keys(tmp2),0)) {
				i = atoi(gen);
				n = atoi(num);
				tell_object(me,
					sprintf("%s�ŵ�%s�ڲ�Ʊ������д�š�"+HIW+"%s"+NOR+"��",
						chinese_number(tmp2[num]), chinese_number(i), number(n)
					)
				);
				if (i == generation-1) {
					switch (check(no1, n)) {
						case 4:
							n = tmp2[num] * award1 / 10 * 9;
							c1 += tmp2[num];
							last_award -= n / 9;
							tell_object(me, "����ϲ����ͷ��������˰�󽱽�"+MONEY_D->money_str(n));
							break;
						case 3:
							n = tmp2[num] * award2;
							c2 += tmp2[num];
							tell_object(me, "����ϲ���˶�������������"+MONEY_D->money_str(n));
							break;
						case 2:
							n = tmp2[num] * award3;
							c3 += tmp2[num];
							tell_object(me, "����ϲ������������������"+MONEY_D->money_str(n));
							break;
						default:
							n = 0;
							tell_object(me, "����ϧû���н�");
					}
					if (n) {
						MONEY_D->pay_player(me, n, 1);
						log_file("LOTTERY", me->query("name")+"��ý���"+MONEY_D->money_str(n), me);
						CHANNEL_D->do_channel(
							this_object(), "chat", "��ϲ"+me->query("name")+RANK_D->query_respect(me)+"��ý���"+MONEY_D->money_str(n)
						);
					}
					last_award -= n;
				}
				tell_object(me, "��\n");
				if (i == generation-1) {
					map_delete(tmp, gen);
					tell_object(me, "��Щ���ڵĲ�Ʊ������������ˡ�\n");
				}
			}
	}
	save();
	me->save();
}

string show_total()
{
	string str, ret;

	if (flag)
		return "���ڿ������ȵȰɡ�\n";

	str = sprintf(
		"�������۵�%s�ڲ�Ʊ��Ŀǰ�ۼƽ���%s���뿪������%s��ʱ��\n"
		"���ڽ���%s���н����룺"+HIG+"%s"+NOR+"\n"
		"%s\n"
		"%s\n"
		"%s\n",
		chinese_number(generation),
		award?MONEY_D->money_str(award):"��",
		chinese_number((find_call_out("kaijiang")+119)/120),
		last_award?"��ʣ"+MONEY_D->money_str(last_award):"��ȫ������",
		number(no1),
		count1?chinese_number(count1)+"ע��ͷ����ÿע����"+MONEY_D->money_str(award1):"ͷ��������",
		count2?chinese_number(count2)+"ע�ж�����ÿע����"+MONEY_D->money_str(award2):"����������",
		count3?chinese_number(count3)+"ע��������ÿע����"+MONEY_D->money_str(award3):"����������"
	);
	ret = "\n";

	foreach (string item in explode(str, "\n"))
		ret += sprintf("%|78s\n", item);
	return ret;
}

private void tongji()
{
	int i;

	count1 = count2 = count3 = 0;
	award1 = award2 = award3 = 0;
	c1 = c2 = c3 = 0;
	if (!sizeof(total))
		return;
	foreach (i in keys(total)) {
		switch (check(i, no1)) {
			case 4:
				count1 += total[i];
				break;
			case 3:
				count2 += total[i];
				break;
			case 2:
				count3 += total[i];
		}
	}
	if (count1)
		award1 = last_award / 2 / count1;
	if (count2)
		award2 = last_award / 10 * 3 / count2;
	if (count3)
		award3 = last_award / 10 * 2 / count3;
}

private void kaijiang()
{
	flag = 1;
	CHANNEL_D->do_channel(this_object(),
		"chat", "��"+chinese_number(generation)+"�ڲ�Ʊ���������λ׼���ñ�īֽ�⣡"
	);
	if (last_award)
		CHANNEL_D->do_channel(this_object(),
			"chat", "����ʣ�ཱ��"+MONEY_D->money_str(last_award)+"���뱾�ڣ�"
		);
	call_out("k1", 3);
}

private void k1()
{
	int i = random(10);

	no1 = i*1000;
	CHANNEL_D->do_channel(this_object(), "chat", "��һλ������ "+chinese_number(i));
	call_out("k2", 1);
}

private void k2()
{
	int i = random(10);

	no1 += i*100;
	CHANNEL_D->do_channel(this_object(), "chat", "�ڶ�λ������ "+chinese_number(i));
	call_out("k3", 1);
}

private void k3()
{
	int i = random(10);

	no1 += i*10;
	CHANNEL_D->do_channel(this_object(), "chat", "����λ������ "+chinese_number(i));
	call_out("k4", 1);
}

private void k4()
{
	int i = random(10);

	no1 += i;
	CHANNEL_D->do_channel(this_object(), "chat", "����λ������ "+chinese_number(i));
	call_out("k5", 1);
}

private void k5()
{
	CHANNEL_D->do_channel(this_object(), "chat",
		sprintf("��%s�ڲ�Ʊ�ĺ����� %s", chinese_number(generation++), number(no1))
	);
	call_out("finish", 2);
}

private void finish()
{
	int i;
	string result;

	last_award += award;
	award = 0;
	tongji();
	i = last_award / 10;

	if (!count1) {
		last_award -= i * 5;
		award += i * 5;
	}
	if (!count2) {
		last_award -= i * 3;
		award += i * 3;
	}
	if (!count3) {
		last_award -= i * 2;
		award += i * 2;
	}

	total = ([ ]);
	flag = 0;
	save();
	call_out("kaijiang", DUR);
	result = replace_string(show_total(), " ", "");
	result = implode(explode(result, "\n"), "�� ");
	CHANNEL_D->do_channel(this_object(), "chat", result);
}
