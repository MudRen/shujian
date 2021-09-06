inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;

	if( !arg )
		return notify_fail("ָ���ʽ��chinese Ӣ��==���� ע�ⲻҪ�пո�\n");

	if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
		if (chinz == "none") {
			write("ɾ��("+key+")("+to_chinese(key)+")��\n");
			CHINESE_D->remove_translate(key);
		} else {
			CHINESE_D->add_translate(key, chinz);
			write("���("+key+")(" + chinz + ")��\n");
		}
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
ָ���ʽ��chinese Ӣ��==����|none
HELP
	);
	return 1 ;
}
