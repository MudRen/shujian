// cp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	int i, j;
	string src, dst, tmps, tmpd;
	mixed file;
	int err;
 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cp <ԭ����> <Ŀ�굵��> \n");

	src = resolve_path(me->query("cwd"), src);
	if (file_size(src) == -2 && src[<1] != '/') src += "/";
	if (src[<1] == '/') src += "*";
	dst = resolve_path(me->query("cwd"), dst);
	if (file_size(dst) == -2 && dst[<1] != '/') dst += "/";
	file = get_dir(src, -1);
	i = sizeof(file);
	if (!i) return notify_fail("û�� "+src+"��\n");
	write(src + " -> " + dst);
	src = "/" + implode(explode(src, "/")[0..<2], "/") + "/";
	while (i--) {
		if (file[i][1] >= 0) {
			tmps = src + file[i][0];
			tmpd = dst;
			if (tmpd[<1] == '/') tmpd += file[i][0];
			write("\n"+tmps+" -> "+tmpd+" ");
			if (tmps == tmpd) {
				write("���ԡ�");
				continue;
			}
			switch ( err = cp(tmps, tmpd) ) {
				case 1:
					write("�ɹ���");
					log_file("static/CP",
                				sprintf("%s(%s)%s\n",
                       		 		me->name(1), geteuid(me),"cp "+tmps+" -> "+tmpd+" �ɹ���"
                				), me
        				);
					j++;
					break;
				case -1:
					write(tmps + " ���ɶ���");
					break;
				case -2:
					write(tmpd + " ����д��");
					break;
				default:
					write("�����룺" + err);
			}
		}
	}
	write("\n"+j+" ���ļ������ɹ���\n");
	return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : cp <ԭ����> <Ŀ�굵��>
 
��ָ�������(��)����������
HELP
    );
    return 1;
}
 
